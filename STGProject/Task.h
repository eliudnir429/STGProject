#pragma once

class task {
public:
	task() = default;
	virtual ~task() = default;
	virtual bool update() = 0;
	virtual void draw() const = 0;
};