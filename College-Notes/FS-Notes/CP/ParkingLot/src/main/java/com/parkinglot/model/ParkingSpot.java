package com.parkinglot.model;

import com.parkinglot.enums.ParkingSpotType;
import java.time.LocalDateTime;

public class ParkingSpot {
    private int spotNumber;
    private ParkingSpotType type;
    private boolean isOccupied;
    private Vehicle vehicle;
    private LocalDateTime lastOccupiedTime;
    private boolean hasChargingStation;
    private boolean isReserved;

    public ParkingSpot(int spotNumber, ParkingSpotType type, boolean hasChargingStation) {
        this.spotNumber = spotNumber;
        this.type = type;
        this.isOccupied = false;
        this.hasChargingStation = hasChargingStation;
        this.isReserved = false;
    }

    public boolean isOccupied() {
        return isOccupied;
    }

    public void park(Vehicle vehicle) {
        this.vehicle = vehicle;
        this.isOccupied = true;
        this.lastOccupiedTime = LocalDateTime.now();
        vehicle.setParkingSpot(this);
    }

    public void removeVehicle() {
        this.vehicle = null;
        this.isOccupied = false;
        this.lastOccupiedTime = null;
    }

    public int getSpotNumber() {
        return spotNumber;
    }

    public ParkingSpotType getType() {
        return type;
    }

    public Vehicle getVehicle() {
        return vehicle;
    }

    public LocalDateTime getLastOccupiedTime() {
        return lastOccupiedTime;
    }

    public boolean hasChargingStation() {
        return hasChargingStation;
    }

    public boolean isReserved() {
        return isReserved;
    }

    public void setReserved(boolean reserved) {
        isReserved = reserved;
    }
} 