package com.parkinglot;

import com.parkinglot.model.*;
import com.parkinglot.enums.ParkingSpotType;
import java.time.LocalDateTime;
import java.time.Duration;
import java.util.*;

public class ParkingLot {
    private List<Level> levels;
    private Map<String, Vehicle> parkedVehicles;
    private Map<String, LocalDateTime> entryTimes;
    private static final double BASE_HOURLY_RATE = 10.0;
    private static final double ELECTRIC_DISCOUNT = 0.2; // 20% discount for electric vehicles
    private static final double HANDICAPPED_DISCOUNT = 0.3; // 30% discount for handicapped vehicles

    public ParkingLot(int numLevels, int motorcycleSpotsPerLevel, 
                     int compactSpotsPerLevel, int largeSpotsPerLevel) {
        this.levels = new ArrayList<>();
        this.parkedVehicles = new HashMap<>();
        this.entryTimes = new HashMap<>();

        for (int i = 0; i < numLevels; i++) {
            levels.add(new Level(i + 1, motorcycleSpotsPerLevel, 
                               compactSpotsPerLevel, largeSpotsPerLevel));
        }
    }

    public boolean parkVehicle(Vehicle vehicle) {
        if (parkedVehicles.containsKey(vehicle.getLicensePlate())) {
            return false; // Vehicle already parked
        }

        for (Level level : levels) {
            if (level.parkVehicle(vehicle)) {
                parkedVehicles.put(vehicle.getLicensePlate(), vehicle);
                entryTimes.put(vehicle.getLicensePlate(), LocalDateTime.now());
                return true;
            }
        }
        return false; // No available spots
    }

    public boolean removeVehicle(String licensePlate) {
        Vehicle vehicle = parkedVehicles.get(licensePlate);
        if (vehicle != null) {
            for (Level level : levels) {
                level.removeVehicle(vehicle);
            }
            parkedVehicles.remove(licensePlate);
            entryTimes.remove(licensePlate);
            return true;
        }
        return false;
    }

    public double calculateParkingFee(String licensePlate) {
        Vehicle vehicle = parkedVehicles.get(licensePlate);
        if (vehicle == null) {
            return 0.0;
        }

        LocalDateTime entryTime = entryTimes.get(licensePlate);
        LocalDateTime exitTime = LocalDateTime.now();
        long hours = Duration.between(entryTime, exitTime).toHours();
        
        double rate = BASE_HOURLY_RATE;
        if (vehicle.isElectric()) {
            rate *= (1 - ELECTRIC_DISCOUNT);
        }
        if (vehicle.isHandicapped()) {
            rate *= (1 - HANDICAPPED_DISCOUNT);
        }

        return hours * rate;
    }

    public Map<ParkingSpotType, Integer> getAvailableSpots() {
        Map<ParkingSpotType, Integer> availableSpots = new HashMap<>();
        for (Level level : levels) {
            for (ParkingSpotType type : ParkingSpotType.values()) {
                availableSpots.merge(type, level.getAvailableSpots(type), Integer::sum);
            }
        }
        return availableSpots;
    }

    public boolean reserveSpot(String licensePlate, ParkingSpotType type) {
        for (Level level : levels) {
            for (ParkingSpot spot : level.getSpots()) {
                if (!spot.isOccupied() && !spot.isReserved() && spot.getType() == type) {
                    spot.setReserved(true);
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        // Create a parking lot with 2 levels
        ParkingLot parkingLot = new ParkingLot(2, 10, 20, 5);

        // Create some vehicles
        Vehicle motorcycle = new Motorcycle("M123", false);
        Vehicle electricCar = new Car("C456", true, false);
        Vehicle handicappedCar = new Car("C789", false, true);
        Vehicle bus = new Bus("B789", false);

        // Park vehicles
        System.out.println("Parking motorcycle: " + parkingLot.parkVehicle(motorcycle));
        System.out.println("Parking electric car: " + parkingLot.parkVehicle(electricCar));
        System.out.println("Parking handicapped car: " + parkingLot.parkVehicle(handicappedCar));
        System.out.println("Parking bus: " + parkingLot.parkVehicle(bus));

        // Get available spots
        Map<ParkingSpotType, Integer> availableSpots = parkingLot.getAvailableSpots();
        System.out.println("\nAvailable spots:");
        availableSpots.forEach((type, count) -> 
            System.out.println(type + ": " + count));

        // Calculate parking fee
        System.out.println("\nParking fees:");
        System.out.println("Motorcycle fee: $" + parkingLot.calculateParkingFee("M123"));
        System.out.println("Electric car fee: $" + parkingLot.calculateParkingFee("C456"));
        System.out.println("Handicapped car fee: $" + parkingLot.calculateParkingFee("C789"));

        // Remove vehicles
        System.out.println("\nRemoving vehicles:");
        System.out.println("Removing motorcycle: " + parkingLot.removeVehicle("M123"));
        System.out.println("Removing electric car: " + parkingLot.removeVehicle("C456"));
    }
} 