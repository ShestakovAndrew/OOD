#pragma once
#include "Observer.h"
#include "WeatherData.h"

typedef IObservable<SWeatherInfo> ObservableType;

class CRemovedObserverTest : public IObserver<SWeatherInfo>
{
public:
	CRemovedObserverTest(ObservableType& observable)
	{
		m_observable = &observable;
	}

private:
	void Update(SWeatherInfo const& data)
	{
		m_observable->RemoveObserver(*this);

		std::cout << "Current Temperature: " << data.temperature << std::endl;
		std::cout << "Current Humidity: " << data.humidity << std::endl;
		std::cout << "Current Pressure: " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
	}

	ObservableType* m_observable;
};

class CPriorityObserverTest : public IObserver<SWeatherInfo>
{
public:
	CPriorityObserverTest(std::ostream& out, size_t selfNumber)
		: m_mySelfNumber(selfNumber)
		, m_out(out)
	{
	}

private:
	void Update(SWeatherInfo const& data)
	{
		m_out << m_mySelfNumber;
	}

	size_t m_mySelfNumber;
	std::ostream& m_out;
};