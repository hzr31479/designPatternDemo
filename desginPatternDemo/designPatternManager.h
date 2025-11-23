/*-----------------designPatternManger 设计模式管理器-----------------*/
#pragma once
#include <memory>
#include <string>
#include <chrono>
#include <iostream>
#include <iomanip>

// 设计模式枚举
enum class DesignPatternType {
    // 创建型模式 (1-5)
    SIMPLE_FACTORY = 1,      // 简单工厂模式
    FACTORY_METHOD = 2,      // 工厂方法模式  
    ABSTRACT_FACTORY = 3,    // 抽象工厂模式
    SINGLETON = 4,          // 单例模式
    BUILDER = 5,            // 建造者模式
    PROTOTYPE = 6,          // 原型模式

    // 结构型模式 (7-13)
    ADAPTER = 7,            // 适配器模式
    BRIDGE = 8,             // 桥接模式
    COMPOSITE = 9,          // 组合模式
    DECORATOR = 10,         // 装饰者模式
    FACADE = 11,            // 外观模式
    FLYWEIGHT = 12,         // 享元模式
    PROXY = 13,             // 代理模式

    // 行为型模式 (14-23)
    CHAIN_OF_RESPONSIBILITY = 14,    // 责任链模式
    COMMAND = 15,                    // 命令模式
    INTERPRETER = 16,                // 解释器模式
    ITERATOR = 17,                   // 迭代器模式
    MEDIATOR = 18,                   // 中介者模式
    MEMENTO = 19,                    // 备忘录模式
    OBSERVER = 20,                   // 观察者模式
    STATE = 21,                      // 状态模式
    STRATEGY = 22,                   // 策略模式
    TEMPLATE_METHOD = 23,            // 模板方法模式
    VISITOR = 24,                    // 访问者模式

    UNKNOWN = 0                      // 未知模式
};

class designPatternManger
{
public:
	designPatternManger() {};
	~designPatternManger() {};

	// 通过类型运行设计模式
	void runDesignPatternByType(const DesignPatternType& type);

private:
	/*-----------创建型模式---------------*/
	// 运行简单工厂模式
	void runSimpleFactoryPattern();
	// 运行工厂方法模式
	void runFactoryMethodPattern();
	// 运行抽象工厂模式
	void runAbstractFactoryPattern();
	// 运行单例模式
	void runSingletonPattern();
	// 运行建造者模式
	void runBuilderPattern();
	// 运行原型模式
	void runPrototypePattern();
	/*-----------结构型模式---------------*/
	// 运行适配器模式
	void runAdapterPattern();
	// 运行桥接模式
	void runBridgePattern();
	// 运行组合模式
	void runCompositePattern();
	// 运行装饰者模式
	void runDecoratorPattern();
	// 运行外观模式
	void runFacadePattern();
	// 运行享元模式
	void runFlyweightPattern();
	/*-----------行为型模式---------------*/
	// 运行责任链模式
	void runChainOfResponsibilityPattern();
	// 运行命令模式
	void runCommandPattern();
	// 运行解释器模式
	void runInterpreterPattern();
	// 运行迭代器模式
	void runIteratorPattern();
	// 运行中介者模式
	void runMediatorPattern();
	// 运行备忘录模式
	void runMementoPattern();
	// 运行观察者模式
	void runObserverPattern();

};
