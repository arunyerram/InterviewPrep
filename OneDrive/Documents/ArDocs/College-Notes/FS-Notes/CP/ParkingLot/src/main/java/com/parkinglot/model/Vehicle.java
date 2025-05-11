package com.parkinglot.model;

import com.parkinglot.enums.VehicleType;
import java.time.LocalDateTime;

public abstract class Vehicle {
    private String licensePlate;
    private VehicleType type;
    private ParkingSpot parkingSpot;
    private LocalDateTime entryTime;
    private LocalDateTime exitTime;
    private boolean isElectric;
    private boolean isHandicapped;

    public Vehicle(String licensePlate, VehicleType type, boolean isElectric, boolean isHandicapped) {
        this.licensePlate = licensePlate;
        this.type = type;
        this.isElectric = isElectric;
        this.isHandicapped = isHandicapped;
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

    public LocalDateTime getEntryTime() {
        return entryTime;
    }

    public void setEntryTime(LocalDateTime entryTime) {
        this.entryTime = entryTime;
    }

    public LocalDateTime getExitTime() {
        return exitTime;
    }

    public void setExitTime(LocalDateTime exitTime) {
        this.exitTime = exitTime;
    }

    public boolean isElectric() {
        return isElectric;
    }

    public boolean isHandicapped() {
        return isHandicapped;
    }
} 