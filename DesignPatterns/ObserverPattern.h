#pragma once 

#include <iostream>
#include <string>
#include <vector>




class Observer
{
    public:
        virtual void update(float, float, float ) = 0;


    private:

};


class Observable
{
    public:
        virtual void add(Observer* observer) = 0;
        virtual void remove(Observer* observer) = 0;
        virtual void notify() = 0;


    private:

};

class WeatherStation: public Observable
{
    public:
        void add(Observer* observer) override
        {
            _observers.push_back(observer);
        }

        void notify() override
        {
            for( auto *it: _observers )
            {
                it->update(_temperature, _humidity, _pressure);
            }
        }

        void remove(Observer* observer) override
        {
            auto iterator = std::find(_observers.begin(), _observers.end(), observer);

            if (iterator != _observers.end()) { // observer found
                _observers.erase(iterator); // remove the observer
            }
        }

        int getTemperature() const
        {
            return _temperature;
        }

        void setState(float temp, float humidity, float pressure) {
            this->_temperature = temp;
            this->_humidity = humidity;
            this->_pressure = pressure;
            std::cout << std::endl;
            notify();
        }

    private:
        float _temperature = 0.0f;
        float _humidity = 0.0f;
        float _pressure = 0.0f;
        std::vector<Observer*> _observers;
};

class PhoneDisplay: Observer
{
    public:
        PhoneDisplay(WeatherStation *station): _station(station)
        {

        }

        void update(float temp, float humidity, float pressure) override
        {
            this->_station->getTemperature();
        }

        
    private:
        WeatherStation* _station;

};

class Client : public Observer {

    private:
        int _id;

    public:

        Client(int id): _id(id) {}

        virtual void update(float temp, float humidity, float pressure) override
        {
            // print the changed values
            std::cout << "---Client (" << _id << ") Data---\tTemperature: " << temp
                    << "\tHumidity: " << humidity
                    << "\tPressure: " << pressure
                    << std::endl;
        }

};


void ClientCodeObserver()
{
    WeatherStation weatherStation;
    Client one(1), two(2), three(3);

    weatherStation.add(&one);
    weatherStation.add(&two);
    weatherStation.add(&three);

    float temp, humidity, pressure;


    std::cout << "Enter Temperature, Humidity, Pressure (seperated by spaces) << ";
    std::cin >> temp >> humidity >> pressure;

    weatherStation.setState(temp,humidity,pressure);

    weatherStation.remove(&two);

    std::cout << "\n\nEnter Temperature, Humidity, Pressure (seperated by spaces) << ";
    std::cin >> temp >> humidity >> pressure;

    weatherStation.setState(temp,humidity,pressure);
}