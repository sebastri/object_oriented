#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"



using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
	
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window&) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};

class Face : public Emoji {
	private:
	Circle ansikt;

	public:
	void attach_to(Graph_lib::Window& win) override = 0;
	Face(Point c, int r);

};

class EmptyFace : public Face{
	private:
	Circle leftEye;
	Circle rightEye;
	public:
	void attach_to(Graph_lib::Window& win);
	void attach_to2(Graph_lib::Window& win);
	EmptyFace(Point c, int r);
};


class SmilingFace : public EmptyFace{
	private:
	Arc smile;
	public:
	SmilingFace(Point c, int r): EmptyFace{c,r}, smile{Point{c.x, c.y + r/3}, r, r/2, 180, 360}{};
	void attach_to(Graph_lib::Window& win) {
		EmptyFace::attach_to(win);
		win.attach(smile);
	}
};
class SmilingFace2 : public EmptyFace{
	private:
	Arc smile;
	public:
	SmilingFace2(Point c, int r): EmptyFace{c,r}, smile{Point{c.x, c.y + r/3}, r, r/2, 180, 360}{};
	void attach_to(Graph_lib::Window& win) {
		EmptyFace::attach_to2(win);
		win.attach(smile);
	}
};
class SadFace : public EmptyFace{
	private:
	Arc sad;
	public:
	SadFace(Point c, int r): EmptyFace{c,r}, sad{Point{c.x, c.y + r/2}, r, r/2, 0, 180}{};
	void attach_to(Graph_lib::Window& win){
		EmptyFace::attach_to(win);
		win.attach(sad);
	}
};

class AngryFace : public SadFace{
	private:
	Arc leftbrow;
	Arc rightbrow;
	public:
	AngryFace(Point c, int r): SadFace{c,r}, leftbrow{Point{c.x-35,c.y-10}, r+15, r+20, 20, 65},
	rightbrow{Point{c.x+35,c.y-10}, r+15, r+20, 180-65, 180-20}{};
	void attach_to(Graph_lib::Window& win){
		SadFace::attach_to(win);
		win.attach(leftbrow);
		win.attach(rightbrow);

	}
};

class WinkingFace : public SmilingFace2{
	private:
	Arc blinkRightEye;
	public:
	WinkingFace(Point c, int r): SmilingFace2{c,r}, blinkRightEye{Point{c.x+16,c.y-14}, r/3, r/3, 0, 180}{};
	void attach_to(Graph_lib::Window& win){
		SmilingFace2::attach_to(win);
		win.attach(blinkRightEye);
	}

};