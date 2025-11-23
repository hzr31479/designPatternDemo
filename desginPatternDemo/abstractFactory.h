/*-------------------------3.抽象工厂方法 abstractFactory-------------------*/
/*
回顾之前的设计模式，简单工厂模式所有逻辑都封装在工厂类中，工厂根据客户提供的产品名字创建对应产品的对象实例；工厂方法模式将产品的创建过程放到了具体工厂类中，每一个工厂可以创建一个具体产品，由此可能会创建许多工厂类。
很多时候，一个工厂不只是生产一种产品，而是生产一类产品，比如一个体育用品工厂，可以生产篮球、足球、排球等多种产品。此时我们可以把这些相关的产品归纳为一个“产品族”，由同一个工厂来生产，这即是抽象工厂模式。
1.抽象工厂模式简介
	抽象工厂模式是常用的创建型设计模式之一。而抽象工厂模式，其抽象程度更高，每一个具体工厂可以生产一组相关的具体产品对象。
抽象工厂模式定义：
	抽象工厂模式：
		提供一个创建一系列相关或相互依赖对象的接口，而无需指定他们具体的类。
		简言之，一个工厂可以提供创建多种相关产品的接口，而无需像工厂方法一样，为每一个产品都提供一个具体工厂。
2.抽象工厂模式结构
	抽象工厂模式结构与工厂方法模式结构类似，不同之处在于，一个具体工厂可以生产多种同类相关的产品：
		抽象工厂（AbstractFactory）：所有生产具体产品的工厂类的基类，提供工厂类的公共方法；
		具体工厂（ConcreteFactory）：生产具体的产品
		抽象产品（AbstractProduct）：所有产品的基类，提供产品类的公共方法
		具体产品（ConcreteProduct）：具体的产品类
3.抽象工厂模式总结
	抽象工厂模式中，如果需要新增加一个系列的产品，比如足球系列，只需增加一族新的具体产品类（抽象和具体）并提供一个对应的工厂类即可。
	优点：
		工厂方法用于创建客户所需产品，同时向客户隐藏某个具体产品类将被实例化的细节，用户只需关心所需产品对应的工厂；
		新加入产品系列时，无需修改原有系统，增强了系统的可扩展性，符合开闭原则。
	缺点：
		在已有产品系列中添加新产品时需要修改抽象层代码，对原有系统改动较大，违背开闭原则
	适用环境：
		一系列/一族产品需要被同时使用时，适合使用抽象工厂模式；
		产品结构稳定，设计完成之后不会向系统中新增或剔除某个产品
*/
#pragma once
#include <iostream>
#include <string>

namespace AbstractFactoryPattern {
	using namespace std;

	// 抽象产品类 球类
	class AbstractBall {
	public:
		AbstractBall() {};
		virtual ~AbstractBall() {};

		virtual void printType() = 0;
		virtual void doSomething() = 0;
	};

	// 抽象产品类 T恤
	class AbstractShirt {
	public:
		AbstractShirt() {};
		virtual ~AbstractShirt() {};

		virtual void printType() = 0;
		virtual void doSomething() = 0;
	};

	// 抽象产品类 鞋子 
	 class AbstractShoes {
	 public:
		AbstractShoes() {};
		virtual ~AbstractShoes() {};

		virtual void printType() = 0;
		virtual void doSomething() = 0;
	 };

	// 具体产品类 篮球
	class basketBall : public AbstractBall {
	public:
		basketBall() {
			printType();
			doSomething();
		};
		~basketBall() {};

		void printType() override {
			std::cout << "This is basketBall" << std::endl;
		}
		void doSomething() override {
			std::cout << "play basketBall" << std::endl;
		}
	};

	// 具体产品类 足球
	class footBall : public AbstractBall {
	public:
		footBall() {
			printType();
			doSomething();
		};
		~footBall() {};

		void printType() override {
			std::cout << "This is footBall" << std::endl;
		}
		void doSomething() override {
			std::cout << "play footBall" << std::endl;
		}
	};

	// 具体产品类 篮球T恤
	class basketBallShirt : public AbstractShirt {
	public:
		basketBallShirt() {
			printType();
			doSomething();
		};
		~basketBallShirt() {};

		void printType() override {
			std::cout << "This is basketBallShirt" << std::endl;
		}
		void doSomething() override {
			std::cout << "swear basketBallShirt" << std::endl;
		}
	};

	// 具体产品类 足球T恤
	class footBallShirt : public AbstractShirt {
	public:
		footBallShirt() {
			printType();
			doSomething();
		};
		~footBallShirt() {};

		void printType() override {
			std::cout << "This is footBallShirt" << std::endl;
		}
		void doSomething() override {
			std::cout << "swear footBallShirt" << std::endl;
		}
	};

	// 具体产品类 篮球鞋
	class basketBallShoes : public AbstractShoes {
	public:
		basketBallShoes() {};
		~basketBallShoes() {};

		void printType() override {
			std::cout << "This is basketBallShoes" << std::endl;
		}
		void doSomething() override {
			std::cout << "swear basketBallShoes" << std::endl;
		}
	};

	// 具体产品类 足球鞋
	class footBallShoes : public AbstractShoes {
	public:
		footBallShoes() {};
		~footBallShoes() {};
		void printType() override {
			std::cout << "This is footBallShoes" << std::endl;
		}
		void doSomething() override {
			std::cout << "swear footBallShoes" << std::endl;
		}
	};

	// 抽象工厂 球类
	class AbstractBallFactory {
	public:
		AbstractBallFactory() {};
		virtual ~AbstractBallFactory() {};

		virtual AbstractBall* getBall() = 0;
		virtual AbstractShirt* getShirt() = 0;
		virtual AbstractShoes* getShoes() = 0;

	};

	// 具体工厂 篮球工厂
	class basketBallFactory : public AbstractBallFactory {
	public:
		basketBallFactory() { std::cout << "create basketBallFactory" << std::endl; };
		virtual ~basketBallFactory() {};

		AbstractBall* getBall() {
			std::cout << "get basketBall" << std::endl;
			return new basketBall();
		}

		AbstractShirt* getShirt() {
			std::cout << "get basketBallShirt" << std::endl;
			return new basketBallShirt();
		}

		AbstractShoes* getShoes() {
			std::cout << "get basketBallShoes" << std::endl;
			return new basketBallShoes();
		}
	};

	// 具体工厂 足球工厂
	class footBallFactory : public AbstractBallFactory {
	public:
		footBallFactory() { std::cout << "create footBallFactory" << std::endl; };
		virtual ~footBallFactory() {};

		AbstractBall* getBall() {
			std::cout << "get footBall" << std::endl;
			return new footBall();
		}

		AbstractShirt* getShirt() {
			std::cout << "getfootBallShirt" << std::endl;
			return new footBallShirt();
		}

		AbstractShoes* getShoes() {
			std::cout << "get footBallShoes" << std::endl;
			return new footBallShoes();
		}
	};


} // namespace AbstractFactoryPattern
