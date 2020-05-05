#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <map>
#include <regex>
#include <string>
#include "IShape.h"
#include <sstream>
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
#include <iostream>

class CShapeProcessor
{
public:
    bool HandleCommand(const std::string& commandLine);
private:
    std::vector <std::shared_ptr<IShape>> m_shapesSet;
    bool CreateLineSegment(const std::string& inputString);
    bool CreateTriangle(const std::string& inputString);
    bool CreateCircle(const std::string& inputString);
    bool CreateRectangle(const std::string& inputString);
    void PrintShapeWithMaxArea() const;
    void PrintShapeWithMinPerimeter() const;
    void DrawShapes() const;
};

