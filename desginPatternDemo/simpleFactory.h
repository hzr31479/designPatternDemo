/*----------------1.简单工厂类---------------------*/
/*
1.简单工厂模式简介
	创建型模式关注对象的创建过程，在软件开发中应用非常广泛。创建型模式描述如何将对象的创建和使用分离，让用户在使用对象过程中无须关心对象的创建细节，从而降低系统耦合度，并且让系统易于修改和扩展。
1.2.简单工厂基本实现流程
	(1).设计一个抽象产品类，它包含一些公共方法的实现；
	(2).从抽象产品类中派生出多个具体产品类，如篮球类、足球类、排球类，具体产品类中实现具体产品生产的相关代码；
	(3).设计一个工厂类，工厂类中提供一个生产各种产品的工厂方法，该方法根据传入参数（产品名称）创建不同的具体产品类对象；
	(4).客户只需调用工厂类的工厂方法，并传入具体产品参数，即可得到一个具体产品对象。
1.3.简单工厂定义
	定义一个简单工厂类，它可以根据参数的不同返回不同类的实例，被创建的实例通常都具有共同的父类
	从简单工厂模式的定义和例子可以看出，在简单工厂模式中，大体上有3个角色：
		(1).工厂（Factory）：根据客户提供的具体产品类的参数，创建具体产品实例；
		(2).抽象产品（AbstractProduct）：具体产品类的基类，包含创建产品的公共方法；
		(3).具体产品（ConcreteProduct）：抽象产品的派生类，包含具体产s品特有的实现方法，是简单工厂模式的创建目标。 简单工厂模式UML类图
1.4简单工厂模式总结
	简单工厂模式的优点在于：
		(1).工厂类提供创建具体产品的方法，并包含一定判断逻辑，客户不必参与产品的创建过程；
		(2).客户只需要知道对应产品的参数即可，参数一般简单好记，如数字、字符或者字符串等。
*/


#ifndef __SIMPLE_FACTORY__
#define __SIMPLE_FACTORY__


#include<iostream>
#include<string>

namespace factorySimple {
	using namespace std;
	// 抽象产品类
	class AbstractProduct {
	public:
		AbstractProduct() {};
		virtual ~AbstractProduct() {};

		virtual void printType() {};
		virtual void doSomething() {};
	};

	// 具体产品类A
	class productA: public AbstractProduct {
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
	class productC: public AbstractProduct {
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

	// 简单工厂类
	class SimpleFactory {
	public:
		static std::shared_ptr<AbstractProduct> getProduct (const string& type) {
			if (type == "A") {
				return std::make_shared<productA>();
			}
			else if (type == "B") {
				return std::make_shared<productB>();
			}
			else if (type == "C") {
				return std::make_shared<productC>();
			}
			else {
				return nullptr;
			}
		}
	};

	#endif //__SIMPLE_FACTORY__

} // namespace factorySimple