#pragma once

 #include "RefillBuilder.h"
 #include <Arduino.h>



class RefillApp {

private:
    // char HS, LS, P0, P1;
    RefillBuilder* builder;


public:

    RefillApp(char HS_, char LS_, char P0_, char P1_){
        // LS = LS_;
        // HS = HS_;
        // P0 = P0_;
        // P1 = P1_;

        builder = new RefillBuilder(HS_, LS_, P0_, P1_);
    };

    void load_setup(){
        builder->setup();
    }

    void run(){
        builder->refill();
    }
    

};
