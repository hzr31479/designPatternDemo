#include "designPatternManager.h"
#include "simpleFactory.h"

using namespace std;

void designPatternManger::runDesignPatternByType(const DesignPatternType& type) {
	if (type <= DesignPatternType::UNKNOWN) {
		std::cout << "请输入有效的设计模式类型！" << std::endl;
		return;
	}
	std::string patternName;

	auto start = std::chrono::high_resolution_clock::now();  

	switch (type) {
		case DesignPatternType::SIMPLE_FACTORY: // 简单工厂模式
			runSimpleFactoryPattern();
			break;
		case DesignPatternType::FACTORY_METHOD: // 工厂方法模式
			 runFactoryMethodPattern();
			break;


		default:
			std::cout << "Design pattern type not recognized." << std::endl;
			break;
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);  

	std::cout << "执行耗时: " << duration.count() << " us" << std::endl;
};

// 运行简单工厂模式
void designPatternManger::runSimpleFactoryPattern() {
	// 创建产品A
	std::shared_ptr<SimpleFactory> factoryA = std::make_shared<SimpleFactory>();
	std::shared_ptr<AbstratcProduct> productA = factoryA->getProduct("A");
	// 创建产品B
	std::shared_ptr<SimpleFactory> factoryB = std::make_shared<SimpleFactory>();
	std::shared_ptr<AbstratcProduct> productB = factoryB->getProduct("B");
	// 创建产品C
	std:shared_ptr<SimpleFactory> factoryC = std::make_shared<SimpleFactory>();
	std::shared_ptr<AbstratcProduct> productC = factoryC->getProduct("C");
}

// 运行工厂方法模式
void designPatternManger::runFactoryMethodPattern() {
	// todo
}

// 运行抽象工厂模式
void designPatternManger::runAbstractFactoryPattern() {
	// todo
}