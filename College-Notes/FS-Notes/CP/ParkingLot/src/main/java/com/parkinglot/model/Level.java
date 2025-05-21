package com.parkinglot.model;

import com.parkinglot.enums.ParkingSpotType;
import java.util.*;

public class Level {
    private int levelNumber;
    private List<ParkingSpot> spots;
    private Map<ParkingSpotType, Integer> availableSpots;
    private Map<ParkingSpotType, List<ParkingSpot>> spotMap;

    public Level(int levelNumber, int motorcycleSpots, int compactSpots, int largeSpots) {
        this.levelNumber = levelNumber;
        this.spots = new ArrayList<>();
        this.availableSpots = new HashMap<>();
        this.spotMap = new HashMap<>();
        
        // Initialize spots
        int spotNumber = 1;
        initializeSpots(ParkingSpotType.MOTORCYCLE, motorcycleSpots, spotNumber);
        spotNumber += motorcycleSpots;
        
        initializeSpots(ParkingSpotType.COMPACT, compactSpots, spotNumber);
        spotNumber += compactSpots;
        
        initializeSpots(ParkingSpotType.LARGE, largeSpots, spotNumber);

        // Initialize available spots count
        availableSpots.put(ParkingSpotType.MOTORCYCLE, motorcycleSpots);
        availableSpots.put(ParkingSpotType.COMPACT, compactSpots);
        availableSpots.put(ParkingSpotType.LARGE, largeSpots);
    }

    private void initializeSpots(ParkingSpotType type, int count, int startNumber) {
        List<ParkingSpot> typeSpots = new ArrayList<>();
        for (int i = 0; i < count; i++) {
            ParkingSpot spot = new ParkingSpot(startNumber + i, type, type == ParkingSpotType.ELECTRIC);
            spots.add(spot);
            typeSpots.add(spot);
        }
        spotMap.put(type, typeSpots);
    }

    public boolean parkVehicle(Vehicle vehicle) {
        ParkingSpotType requiredType = getRequiredSpotType(vehicle);
        if (availableSpots.get(requiredType) > 0) {
            List<ParkingSpot> typeSpots = spotMap.get(requiredType);
            for (ParkingSpot spot : typeSpots) {
                if (!spot.isOccupied() && !spot.isReserved()) {
                    if (vehicle.isElectric() && !spot.hasChargingStation()) {
                        continue;
                    }
                    spot.park(vehicle);
                    availableSpots.put(requiredType, availableSpots.get(requiredType) - 1);
                    return true;
                }
            }
        }
        return false;
    }

    public void removeVehicle(Vehicle vehicle) {
        ParkingSpot spot = vehicle.getParkingSpot();
        if (spot != null) {
            spot.removeVehicle();
            availableSpots.put(spot.getType(), availableSpots.get(spot.getType()) + 1);
        }
    }

    private ParkingSpotType getRequiredSpotType(Vehicle vehicle) {
        if (vehicle.isHandicapped()) {
            return ParkingSpotType.HANDICAPPED;
        }
        return switch (vehicle.getType()) {
            case MOTORCYCLE -> ParkingSpotType.MOTORCYCLE;
            case COMPACT -> ParkingSpotType.COMPACT;
            case LARGE -> ParkingSpotType.LARGE;
            case ELECTRIC -> ParkingSpotType.ELECTRIC;
            default -> ParkingSpotType.COMPACT;
        };
    }

    public int getAvailableSpots(ParkingSpotType type) {
        return availableSpots.getOrDefault(type, 0);
    }

    public List<ParkingSpot> getSpots() {
        return spots;
    }
} 