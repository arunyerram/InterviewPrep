import java.util.*;

// Enum for different vehicle types
enum VehicleType {
    MOTORCYCLE, COMPACT, LARGE
}

// Enum for different parking spot types
enum ParkingSpotType {
    MOTORCYCLE, COMPACT, LARGE
}

// Vehicle class
abstract class Vehicle {
    private String licensePlate;
    private VehicleType type;
    private ParkingSpot parkingSpot;

    public Vehicle(String licensePlate, VehicleType type) {
        this.licensePlate = licensePlate;
        this.type = type;
    }

    public String getLicensePlate() {
        return licensePlate;
    }

    public VehicleType getType() {
        return type;
    }

    public void setParkingSpot(ParkingSpot spot) {
        this.parkingSpot = spot;
    }

    public ParkingSpot getParkingSpot() {
        return parkingSpot;
    }
}

// Concrete vehicle classes
class Motorcycle extends Vehicle {
    public Motorcycle(String licensePlate) {
        super(licensePlate, VehicleType.MOTORCYCLE);
    }
}

class Car extends Vehicle {
    public Car(String licensePlate) {
        super(licensePlate, VehicleType.COMPACT);
    }
}

class Bus extends Vehicle {
    public Bus(String licensePlate) {
        super(licensePlate, VehicleType.LARGE);
    }
}

// Parking Spot class
class ParkingSpot {
    private int spotNumber;
    private ParkingSpotType type;
    private boolean isOccupied;
    private Vehicle vehicle;

    public ParkingSpot(int spotNumber, ParkingSpotType type) {
        this.spotNumber = spotNumber;
        this.type = type;
        this.isOccupied = false;
    }

    public boolean isOccupied() {
        return isOccupied;
    }

    public void park(Vehicle vehicle) {
        this.vehicle = vehicle;
        this.isOccupied = true;
        vehicle.setParkingSpot(this);
    }

    public void removeVehicle() {
        this.vehicle = null;
        this.isOccupied = false;
    }

    public int getSpotNumber() {
        return spotNumber;
    }

    public ParkingSpotType getType() {
        return type;
    }
}

// Level class to represent a floor in the parking lot
class Level {
    private int levelNumber;
    private List<ParkingSpot> spots;
    private Map<ParkingSpotType, Integer> availableSpots;

    public Level(int levelNumber, int motorcycleSpots, int compactSpots, int largeSpots) {
        this.levelNumber = levelNumber;
        this.spots = new ArrayList<>();
        this.availableSpots = new HashMap<>();
        
        // Initialize spots
        int spotNumber = 1;
        for (int i = 0; i < motorcycleSpots; i++) {
            spots.add(new ParkingSpot(spotNumber++, ParkingSpotType.MOTORCYCLE));
        }
        for (int i = 0; i < compactSpots; i++) {
            spots.add(new ParkingSpot(spotNumber++, ParkingSpotType.COMPACT));
        }
        for (int i = 0; i < largeSpots; i++) {
            spots.add(new ParkingSpot(spotNumber++, ParkingSpotType.LARGE));
        }

        // Initialize available spots count
        availableSpots.put(ParkingSpotType.MOTORCYCLE, motorcycleSpots);
        availableSpots.put(ParkingSpotType.COMPACT, compactSpots);
        availableSpots.put(ParkingSpotType.LARGE, largeSpots);
    }

    public boolean parkVehicle(Vehicle vehicle) {
        ParkingSpotType requiredType = getRequiredSpotType(vehicle);
        if (availableSpots.get(requiredType) > 0) {
            for (ParkingSpot spot : spots) {
                if (!spot.isOccupied() && spot.getType() == requiredType) {
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
        switch (vehicle.getType()) {
            case MOTORCYCLE:
                return ParkingSpotType.MOTORCYCLE;
            case COMPACT:
                return ParkingSpotType.COMPACT;
            case LARGE:
                return ParkingSpotType.LARGE;
            default:
                return ParkingSpotType.COMPACT;
        }
    }
}

// Parking Lot class
public class ParkingLot {
    private List<Level> levels;
    private Map<String, Vehicle> parkedVehicles;
    private static final double HOURLY_RATE = 10.0;

    public ParkingLot(int numLevels, int motorcycleSpotsPerLevel, 
                     int compactSpotsPerLevel, int largeSpotsPerLevel) {
        this.levels = new ArrayList<>();
        this.parkedVehicles = new HashMap<>();

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
            return true;
        }
        return false;
    }

    public double calculateParkingFee(String licensePlate, int hours) {
        if (parkedVehicles.containsKey(licensePlate)) {
            return hours * HOURLY_RATE;
        }
        return 0.0;
    }

    public static void main(String[] args) {
        // Create a parking lot with 2 levels
        ParkingLot parkingLot = new ParkingLot(2, 10, 20, 5);

        // Create some vehicles
        Vehicle motorcycle = new Motorcycle("M123");
        Vehicle car = new Car("C456");
        Vehicle bus = new Bus("B789");

        // Park vehicles
        System.out.println("Parking motorcycle: " + parkingLot.parkVehicle(motorcycle));
        System.out.println("Parking car: " + parkingLot.parkVehicle(car));
        System.out.println("Parking bus: " + parkingLot.parkVehicle(bus));

        // Calculate parking fee
        System.out.println("Parking fee for 2 hours: $" + 
                         parkingLot.calculateParkingFee("M123", 2));

        // Remove vehicle
        System.out.println("Removing motorcycle: " + 
                         parkingLot.removeVehicle("M123"));
    }
} 