#pragma once 
#include <iostream>
#include <string>

////////////////////////////
// Hierarchia             //
////////////////////////////

/* 
GameObj - klasa bazowa
Hp - klasa niezależna, przechowuje informacje dotyczące HP 
Character - reprezentuje postacie
Hurting - rodzaj obietków gry, więc dziedziczy po GameObj
Player - postać, więc dziedziczy po Character
Bomb - rodzaj przedmiotu, dziedziczy po Hurting, bo zadaje obrażenia
Boss - postać, która zadaje obrażenia, więc dziedziczy po Hurting i Character
*/


class GameObj
{
public:
	GameObj(const std::string &id ): m_id(id) {}

	virtual void print(std::ostream &o) const = 0; 

	virtual ~GameObj() {};

	std::string id() const { return m_id; }

private:
	std::string m_id;
};

inline std::ostream & operator << (std::ostream & o, const GameObj& other)
{
	other.print(o);
	return o;
}


class HP
{
public:
	HP(unsigned hp): m_hp(hp) {}
	unsigned getHP() const { return m_hp; }
	void setHP(unsigned hp) { m_hp = hp; }


private:
	unsigned  m_hp;
};

class Character: public virtual GameObj
{
public:
	Character(HP hp, const std::string &name, const std::string id): GameObj(id), m_hp(hp), m_name(name) {}

	void print(std::ostream &o) const override 
	{
		o << m_name << ", ma " << hp() ;
	}

	std::string hp() const { return  "[" + std::to_string(m_hp.getHP()) + " HP]"; }

private:
	HP m_hp;
	std::string m_name;
};

class Hurting: public virtual GameObj
{
public:
	Hurting(HP damage, const std::string &id): GameObj(id), m_damage(damage) {}

	void print(std::ostream &o) const override 
	{
		o << "Jego uderzenie odbiera: " << "[" + std::to_string(m_damage.getHP()) + " HP]";
	}

	std::string hp() const { return  "[" + std::to_string(m_damage.getHP()) + " HP]"; }

private:
	HP m_damage;
};

class Player: public Character
{
public:
	Player(HP hp, const std::string &name, const std::string &id): GameObj(id), Character(hp, name, id) {}

	void print(std::ostream &o) const override 
	{
		o << "Player " << static_cast<Character>(*this);
	}

};

class Bomb: public Hurting
{
public:
	Bomb(HP damage, const std::string &id ): GameObj(id), Hurting(damage, id) {}

};


class Boss: public Character, public Hurting
{
public:
	Boss(HP hp, const std::string &name, HP damage,const std::string &id): GameObj(id), Character(hp, name, id), Hurting(damage, id) {}

	void print(std::ostream &o) const override 
	{	
		o << "Bad guy: " << static_cast<Character>(*this) << "\n";
		o << static_cast<Hurting>(*this);
	}
};
