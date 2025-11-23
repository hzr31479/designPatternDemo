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
		case DesignPatternType::SIMPLE_FACTORY:		// 简单工厂模式
			runSimpleFactoryPattern();
			break;
		case DesignPatternType::FACTORY_METHOD:		// 工厂方法模式
			 runFactoryMethodPattern();
			break;
		case DesignPatternType::ABSTRACT_FACTORY:	//	抽象工厂模式
			runAbstractFactoryPattern();
			break;
		case DesignPatternType::SINGLETON:			// 单例模式
			// runSingletonPattern();
			break;
		case DesignPatternType::BUILDER:			// 建造者模式
			// runBuilderPattern();
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
	// 创建简单工厂
	std::shared_ptr<factorySimple::SimpleFactory> factory = std::make_shared<factorySimple::SimpleFactory>();
	// 创建产品A
	std::shared_ptr<factorySimple::AbstractProduct> productA = factory->getProduct("A");
	// 创建产品B
	std::shared_ptr<factorySimple::AbstractProduct> productB = factory->getProduct("B");
	// 创建产品C
	std::shared_ptr<factorySimple::AbstractProduct> productC = factory->getProduct("C");
}

// 运行工厂方法模式
void designPatternManger::runFactoryMethodPattern() {
	std::cout << "执行工厂方法模式" << std::endl;
	// 创建具体工厂A
	std::shared_ptr<factoryMethod::AbstractFactory> factoryA = std::make_shared<factoryMethod::ConcreteFactoryA>();
	// 获取具体产品
	auto productA = factoryA->getConcreteProduct();
	// 创建具体工厂B
	std::shared_ptr<factoryMethod::AbstractFactory> factoryB = std::make_shared<factoryMethod::ConcreteFactoryB>();
	// 获取具体产品
	auto productB = factoryB->getConcreteProduct();
	// 创建具体工厂C
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

// 运行单例模式
void designPatternManger::runSingletonPattern() {

}

// 运行建造者模式
void designPatternManger::runBuilderPattern() {
}

// 运行原型模式
void designPatternManger::runPrototypePattern() {
}
// 运行适配器模式
void designPatternManger::runAdapterPattern() {
}
// 运行桥接模式
void designPatternManger::runBridgePattern() {
}
// 运行组合模式
void designPatternManger::runCompositePattern() {
}
// 运行装饰者模式
void designPatternManger::runDecoratorPattern() {
}
// 运行外观模式
void designPatternManger::runFacadePattern() {
}
// 运行享元模式
void designPatternManger::runFlyweightPattern() {
}
// 运行责任链模式
void designPatternManger::runChainOfResponsibilityPattern() {
}
// 运行命令模式
void designPatternManger::runCommandPattern() {
}
// 运行解释器模式
void designPatternManger::runInterpreterPattern() {
}
// 运行迭代器模式
void designPatternManger::runIteratorPattern() {
}
// 运行中介者模式
void designPatternManger::runMediatorPattern() {
}
// 运行备忘录模式
void designPatternManger::runMementoPattern() {
}
// 运行观察者模式
void designPatternManger::runObserverPattern() {
}

