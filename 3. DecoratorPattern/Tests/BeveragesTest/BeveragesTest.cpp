#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "Condiments.h"
#include "Beverages.h"

template <typename Condiment, typename... Args>
auto MakeCondiment(const Args&... args)
{
	return [=](auto&& b) {
		return std::make_unique<Condiment>(std::forward<decltype(b)>(b), args...);
	};
}

template <typename Component, typename Decorator>
auto operator<<(Component&& component, const Decorator& decorate)
{
	return decorate(std::forward<Component>(component));
}

TEST_CASE("Beverages Tests:")
{
	SECTION("Cappuccino should be the size passed to constructor.")
	{
		CCappuccino standartCappuccino{ CoffeSize::Standart };
		REQUIRE(standartCappuccino.GetDescription() == "Standart Cappuccino");
		REQUIRE(standartCappuccino.GetCost() == 80);

		CCappuccino doubleCappuccino{ CoffeSize::Double };
		REQUIRE(doubleCappuccino.GetDescription() == "Double Cappuccino");
		REQUIRE(doubleCappuccino.GetCost() == 120);

		SECTION("Default Cappuccino must be standard size")
		{
			CCappuccino cappuccino{};
			REQUIRE(cappuccino.GetDescription() == "Standart Cappuccino");
			REQUIRE(cappuccino.GetCost() == 80);
		}
	}

	SECTION("Latte should be the size passed to constructor.")
	{
		CLatte standartLatte{ CoffeSize::Standart };
		REQUIRE(standartLatte.GetDescription() == "Standart Latte");
		REQUIRE(standartLatte.GetCost() == 90);

		CLatte doubleLatte{ CoffeSize::Double };
		REQUIRE(doubleLatte.GetDescription() == "Double Latte");
		REQUIRE(doubleLatte.GetCost() == 130);

		SECTION("Default Latte must be standard size")
		{
			CLatte latte{};
			REQUIRE(latte.GetDescription() == "Standart Latte");
			REQUIRE(latte.GetCost() == 90);
		}
	}

	SECTION("Tea should be the type passed to constructor.")
	{
		CTea blackTea{ TeaType::Black };
		REQUIRE(blackTea.GetDescription() == "Black Tea");
		REQUIRE(blackTea.GetCost() == 30);

		CTea greenTea{ TeaType::Green };
		REQUIRE(greenTea.GetDescription() == "Green Tea");
		REQUIRE(greenTea.GetCost() == 30);

		CTea whiteTea{ TeaType::White };
		REQUIRE(whiteTea.GetDescription() == "White Tea");
		REQUIRE(whiteTea.GetCost() == 30);

		CTea yellowTea{ TeaType::Yellow };
		REQUIRE(yellowTea.GetDescription() == "Yellow Tea");
		REQUIRE(yellowTea.GetCost() == 30);

		SECTION("Default tea should be green.")
		{
			CTea tea{};
			REQUIRE(tea.GetDescription() == "Green Tea");
			REQUIRE(tea.GetCost() == 30);
		}
	}

	SECTION("Milkshake should be the size passed to constructor.")
	{
		CMilkshake smallMilkshake{ MilkshakeSize::Small };
		REQUIRE(smallMilkshake.GetDescription() == "Small Milkshake");
		CHECK(smallMilkshake.GetCost() == 50);

		CMilkshake mediumMilkshake{ MilkshakeSize::Medium };
		REQUIRE(mediumMilkshake.GetDescription() == "Medium Milkshake");
		REQUIRE(mediumMilkshake.GetCost() == 60);

		CMilkshake largeMilkshake{ MilkshakeSize::Large };
		REQUIRE(largeMilkshake.GetDescription() == "Large Milkshake");
		REQUIRE(largeMilkshake.GetCost() == 80);

		SECTION("Default Milkshake should be medium size.")
		{
			CMilkshake milkshake{};
			REQUIRE(milkshake.GetDescription() == "Medium Milkshake");
			REQUIRE(milkshake.GetCost() == 60);
		}
	}
}

TEST_CASE("Condiments Tests:")
{
	SECTION("Making a extra beverage with all condiments should be successful.")
	{
		auto beverage = std::make_unique<CLatte>(CoffeSize::Double)
			<< MakeCondiment<CCinnamon>()
			<< MakeCondiment<CLemon>(3)
			<< MakeCondiment<CIceCubes>(2, IceCubeType::Dry)
			<< MakeCondiment<CIceCubes>(2, IceCubeType::Water)
			<< MakeCondiment<CSyrup>(SyrupType::Chocolate)
			<< MakeCondiment<CSyrup>(SyrupType::Maple)
			<< MakeCondiment<CChocolateCrumbs>(4)
			<< MakeCondiment<CCoconutFlakes>(4)
			<< MakeCondiment<CCream>()
			<< MakeCondiment<CChocolate>(5)
			<< MakeCondiment<CLiquor>(LiquorType::Chocolate)
			<< MakeCondiment<CLiquor>(LiquorType::Nut);

		REQUIRE(beverage->GetDescription() == "Double Latte, Cinnamon, Lemon x 3, Dry ice cubes x 2, Water ice cubes x 2, Chocolate syrup, Maple syrup, Chocolate crumbs 4g, Coconut flakes 4g, Cream, Chocolate x 5 slices, Chocolate liquor, Nut liquor");
		REQUIRE(beverage->GetCost() == 427);
	}

	SECTION("Making a beverage with cream should be successful.")
	{
		auto beverage = std::make_unique<CCoffee>()
			<< MakeCondiment<CCream>();

		REQUIRE(beverage->GetDescription() == "Coffee, Cream");
		REQUIRE(beverage->GetCost() == 85);
	}

	SECTION("Add more than 5 slices of chocolate should`t.")
	{
		auto beverage = std::make_unique<CMilkshake>()
			<< MakeCondiment<CChocolate>(6);

		REQUIRE(beverage->GetDescription() == "Medium Milkshake, Chocolate x 5 slices");
		REQUIRE(beverage->GetCost() == 110);
	}

	SECTION("Making a beverage with liqour should be successful.")
	{
		auto beverage = std::make_unique<CCoffee>()
			<< MakeCondiment<CLiquor>(LiquorType::Chocolate)
			<< MakeCondiment<CLiquor>(LiquorType::Nut);

		REQUIRE(beverage->GetDescription() == "Coffee, Chocolate liquor, Nut liquor");
		REQUIRE(beverage->GetCost() == 160);
	}
}