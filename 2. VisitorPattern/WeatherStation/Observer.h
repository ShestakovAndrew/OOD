#pragma once

#include <map>
#include <functional>

/*
��������� ��������� IObserver. ��� ������ ������������� �����,
�������� �������� ����������� �� ���������������� IObservable
���������� ������� �������� ��� ���������,
������������� ����������� � ����� Update
*/
template <typename T>
class IObserver
{
public:
	virtual void Update(T const& data) = 0;
	virtual ~IObserver() = default;
};

/*
��������� ��������� IObservable. ��������� ����������� � ���������� �� ����������, � �����
������������ �������� ����������� ������������������ ������������.
*/
template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T>& observer, size_t priority) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T>& observer) = 0;
};

// ���������� ���������� IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType& observer, size_t priority) override
	{
		m_observers.emplace(priority, &observer);
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();
		auto observers = m_observers;

		for (auto it = observers.rbegin(); it != observers.rend(); ++it)
		{
			it->second->Update(data);
		}
	}

	void RemoveObserver(ObserverType& observer) override
	{
		for (auto it = m_observers.begin(); it != m_observers.end(); ++it)
		{
			if (it->second == &observer)
			{
				m_observers.erase(it);
				break;
			}
		}
	}

protected:
	// ������-���������� ������ ����������� ������ �����,
	// � ������� ���������� ���������� �� ���������� � �������
	virtual T GetChangedData() const = 0;

private:
	std::multimap<size_t, ObserverType*> m_observers;
};
