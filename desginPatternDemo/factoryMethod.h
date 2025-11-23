/*------------2.工厂方法类 factoryMethod---------------*/
/*
1.工厂方法模式简介
	简单工厂模式中，每新增一个具体产品，就需要修改工厂类内部的判断逻辑。为了不修改工厂类，遵循开闭原则，工厂方法模式中不再使用工厂类统一创建所有的具体产品，而是针对不同的产品设计了不同的工厂，每一个工厂只生产特定的产品。
工厂方法模式定义：
	定义一个用于创建对象的接口，但是让子类决定将哪一个类实例化。工厂方法模式让一个类的实例化延迟到其子类。
2.工厂方法模式结构
	从工厂方法模式简介中，可以知道该模式有以下几种角色：
		抽象工厂（AbstractFactory）：所有生产具体产品的工厂类的基类，提供工厂类的公共方法；
		具体工厂（ConcreteFactory）：生产具体的产品
		抽象产品（AbstractProduct）：所有产品的基类，提供产品类的公共方法
3.工厂方法模式总结
	如果想使用新产品，只需要增加一个新的产品工厂，然后在客户端代码中修改具体工厂类的类名，而原有的类的代码无需修改。由此可看到，相较简单工厂模式，工厂方法模式更加符合开闭原则。工厂方法是使用频率最高的设计模式之一，是很多开源框架和API类库的核心模式。
优点：
	工厂方法用于创建客户所需产品，同时向客户隐藏某个具体产品类将被实例化的细节，用户只需关心所需产品对应的工厂；
	工厂自主决定创建何种产品，并且创建过程封装在具体工厂对象内部，多态性设计是工厂方法模式的关键；
	新加入产品时，无需修改原有代码，增强了系统的可扩展性，符合开闭原则。
缺点：
	添加新产品时需要同时添加新的产品工厂，系统中类的数量成对增加，增加了系统的复杂度，更多的类需要编译和运行，增加了系统的额外开销；
	工厂和产品都引入了抽象层，客户端代码中均使用的抽象层（AbstractFactory和AbstractSportProduct ），增加了系统的抽象层次和理解难度。
适用环境：
	客户端不需要知道它所需要创建的对象的类；
	抽象工厂类通过其子类来指定创建哪个对象（运用多态性设计和里氏代换原则）
*/
#ifndef FACTORY_METHOD_H  
#define FACTORY_METHOD_H


#pragma once
#include<iostream>
#include<string>

namespace factoryMethod {
	using namespace std;

	// 抽象产品类
	class AbstractProduct {
	public:
		AbstractProduct() {};
		virtual ~AbstractProduct() {};

		virtual void printType() = 0;
		virtual void doSomething()= 0;
	};

	// 具体产品类A
	class productA : public AbstractProduct {
	public:
		productA() {
			printType();
			doSomething();
		};
		~productA() {};

		void printType() override {
			std::cout << "This is product A" << std::endl;
		}
		void doSomething() override {
			std::cout << "Product A is doing something" << std::endl;
		}
	};

	// 具体产品类B
	class productB : public AbstractProduct {
	public:
		productB() {
			printType();
			doSomething();
		};
		~productB() {};

		void printType() override {
			std::cout << "This is product B" << std::endl;
		}
		void doSomething() override {
			std::cout << "Product B is doing something" << std::endl;
		}
	};

	// 具体产品类C
	class productC : public AbstractProduct {
	public:
		productC() {
			printType();
			doSomething();
		};
		~productC() {};

		void printType() override {
			std::cout << "This is product C" << std::endl;
		}
		void doSomething() override {
			std::cout << "Product C is doing something" << std::endl;
		}
	};


	// 抽象工厂类
	class AbstractFactory {
	public:
		AbstractFactory() {};
		virtual ~AbstractFactory() {};

		virtual AbstractProduct* getConcreteProduct() = 0;

	};

	class ConcreteFactoryA : public AbstractFactory {
	public:
		ConcreteFactoryA() { std::cout << "create ConcreteFactoryA" << std::endl; };
		virtual ~ConcreteFactoryA() {};

		AbstractProduct* getConcreteProduct() {
			std::cout << "get productA" << std::endl;
			return new productA();
		}
	};

	class ConcreteFactoryB : public AbstractFactory {
	public:
		ConcreteFactoryB() { std::cout << "create ConcreteFactoryA" << std::endl; };
		virtual ~ConcreteFactoryB() {};

		AbstractProduct* getConcreteProduct() {
			std::cout << "get productB" << std::endl;
			return new productB();
		}
	};

	class ConcreteFactoryC : public AbstractFactory {
	public:
		ConcreteFactoryC() { std::cout << "create ConcreteFactoryA" << std::endl; };
		virtual ~ConcreteFactoryC() {};

		AbstractProduct* getConcreteProduct() {
			std::cout << "get productC" << std::endl;
			return new productC();
		}
	};
}

#endif // FACTORY_METHOD_H