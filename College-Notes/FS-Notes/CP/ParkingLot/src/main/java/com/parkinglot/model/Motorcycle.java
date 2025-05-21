package com.parkinglot.model;

import com.parkinglot.enums.VehicleType;

public class Motorcycle extends Vehicle {
    public Motorcycle(String licensePlate, boolean isElectric) {
        super(licensePlate, VehicleType.MOTORCYCLE, isElectric, false);
    }
} 