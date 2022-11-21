#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

#include "Observer.h"

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

class CDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		std::cout << "Current Temperature: " << data.temperature << std::endl;
		std::cout << "Current Humidity: " << data.humidity << std::endl;
		std::cout << "Current Pressure: " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
	}
};

class CStatisticData
{
public:	
	void Update(double value)
	{
		m_min = std::min(m_min, value);
		m_max = std::max(m_max, value);
		m_acc += value;
		++m_countAcc;
	}

	void PrintInfo()
	{
		std::cout << "min: " + std::to_string(m_min) << std::endl;
		std::cout << "max: " + std::to_string(m_max) << std::endl;
		std::cout << "taverage: " + std::to_string(m_acc / m_countAcc) << std::endl;
		std::cout << "----------------" << std::endl;
	}

private:
	double m_min = std::numeric_limits<double>::infinity();
	double m_max = -std::numeric_limits<double>::infinity();
	double m_acc = 0;
	size_t m_countAcc = 0;
};

class CStatsDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		m_temperatureStatisticData.Update(data.temperature);
		m_humidityStatisticData.Update(data.humidity);
		m_pressureStatisticData.Update(data.pressure);

		std::cout << "Temperature: " << std::endl; m_temperatureStatisticData.PrintInfo();
		std::cout << "Humidity: " << std::endl; m_humidityStatisticData.PrintInfo();
		std::cout << "Pressure: " << std::endl; m_pressureStatisticData.PrintInfo();
	}

	CStatisticData m_temperatureStatisticData;
	CStatisticData m_humidityStatisticData;
	CStatisticData m_pressureStatisticData;
};

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	// Температура в градусах Цельсия
	double GetTemperature() const
	{
		return m_temperature;
	}
	// Относительная влажность (0...100)
	double GetHumidity() const
	{
		return m_humidity;
	}
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure() const
	{
		return m_pressure;
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure)
	{
		m_humidity = humidity;
		m_temperature = temp;
		m_pressure = pressure;

		MeasurementsChanged();
	}
protected:
	SWeatherInfo GetChangedData() const override
	{
		SWeatherInfo info;
		info.temperature = GetTemperature();
		info.humidity = GetHumidity();
		info.pressure = GetPressure();
		return info;
	}
private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;
};
