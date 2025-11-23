#include "designPatternManager.h"
#include "simpleFactory.h"
#include "factoryMethod.h"
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
	std::cout << "执行简单工厂模式" << std::endl;
	// 创建产品A
	std::shared_ptr<factorySimple::SimpleFactory> factoryA = std::make_shared<factorySimple::SimpleFactory>();
	std::shared_ptr<factorySimple::AbstractProduct> productA = factoryA->getProduct("A");
	// 创建产品B
	std::shared_ptr<factorySimple::SimpleFactory> factoryB = std::make_shared<factorySimple::SimpleFactory>();
	std::shared_ptr<factorySimple::AbstractProduct> productB = factoryB->getProduct("B");
	// 创建产品C
	std:shared_ptr<factorySimple::SimpleFactory> factoryC = std::make_shared<factorySimple::SimpleFactory>();
	std::shared_ptr<factorySimple::AbstractProduct> productC = factoryC->getProduct("C");
}

// 运行工厂方法模式
void designPatternManger::runFactoryMethodPattern() {
	std::cout << "执行工厂方法模式" << std::endl;
	// 直接创建具体类
	std::shared_ptr<factoryMethod::AbstractFactory> factoryA = std::make_shared<factoryMethod::ConcreteFactoryA>();
	// 获取具体产品
	auto productA = factoryA->getConcreteProduct();

	// 直接创建具体类
	std::shared_ptr<factoryMethod::AbstractFactory> factoryB = std::make_shared<factoryMethod::ConcreteFactoryB>();
	// 获取具体产品
	auto productB = factoryB->getConcreteProduct();

	// 直接创建具体类
	std::shared_ptr<factoryMethod::AbstractFactory> factoryC = std::make_shared<factoryMethod::ConcreteFactoryC>();
	// 获取具体产品
	auto productC = factoryC->getConcreteProduct();

	delete productA;
	delete productB;
	delete productC;
}

// 运行抽象工厂模式
void designPatternManger::runAbstractFactoryPattern() {
	// todo
}