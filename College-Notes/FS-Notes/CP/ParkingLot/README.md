# Parking Lot System

A comprehensive parking lot management system implemented in Java with various features and capabilities.

## Features

1. **Multi-level Parking**
   - Support for multiple parking levels
   - Different types of parking spots on each level
   - Efficient spot allocation and management

2. **Vehicle Types**
   - Motorcycle
   - Car (Compact)
   - Bus (Large)
   - Support for electric vehicles
   - Support for handicapped vehicles

3. **Parking Spot Types**
   - Motorcycle spots
   - Compact spots
   - Large spots
   - Electric vehicle spots with charging stations
   - Handicapped spots

4. **Smart Parking Features**
   - Automatic spot allocation based on vehicle type
   - Support for electric vehicle charging
   - Handicapped parking priority
   - Spot reservation system

5. **Pricing System**
   - Base hourly rate
   - Discounts for electric vehicles (20%)
   - Discounts for handicapped vehicles (30%)
   - Time-based fee calculation

6. **Management Features**
   - Track available spots
   - Monitor parked vehicles
   - Calculate parking fees
   - Handle vehicle entry and exit

## Project Structure

```
ParkingLot/
├── src/
│   └── main/
│       └── java/
│           └── com/
│               └── parkinglot/
│                   ├── enums/
│                   │   ├── VehicleType.java
│                   │   └── ParkingSpotType.java
│                   ├── model/
│                   │   ├── Vehicle.java
│                   │   ├── Motorcycle.java
│                   │   ├── Car.java
│                   │   ├── Bus.java
│                   │   ├── ParkingSpot.java
│                   │   └── Level.java
│                   └── ParkingLot.java
└── README.md
```

## Usage

1. Create a parking lot:
```java
ParkingLot parkingLot = new ParkingLot(2, 10, 20, 5);  // 2 levels, 10 motorcycle spots, 20 compact spots, 5 large spots per level
```

2. Park vehicles:
```java
Vehicle motorcycle = new Motorcycle("M123", false);
Vehicle electricCar = new Car("C456", true, false);
parkingLot.parkVehicle(motorcycle);
parkingLot.parkVehicle(electricCar);
```

3. Calculate fees:
```java
double fee = parkingLot.calculateParkingFee("M123");
```

4. Remove vehicles:
```java
parkingLot.removeVehicle("M123");
```

## Future Enhancements

1. Payment processing integration
2. Monthly/yearly parking passes
3. Real-time spot availability display
4. Mobile app integration
5. Security camera integration
6. Automated entry/exit gates
7. Parking spot sensors
8. Dynamic pricing based on demand 