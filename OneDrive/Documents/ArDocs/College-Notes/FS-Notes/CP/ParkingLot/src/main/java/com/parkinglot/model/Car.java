package com.parkinglot.model;

import com.parkinglot.enums.VehicleType;

public class Car extends Vehicle {
    public Car(String licensePlate, boolean isElectric, boolean isHandicapped) {
        super(licensePlate, VehicleType.COMPACT, isElectric, isHandicapped);
    }
} 