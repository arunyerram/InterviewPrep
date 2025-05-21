package com.parkinglot.model;

import com.parkinglot.enums.VehicleType;

public class Bus extends Vehicle {
    public Bus(String licensePlate, boolean isElectric) {
        super(licensePlate, VehicleType.LARGE, isElectric, false);
    }
} 