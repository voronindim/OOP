#include "CShapeProcessor.h"
#include "CCanvas.h"
#include <sstream>

const std::map<std::string, std::string> shapes = {
        {"LineSegment", "^([[:alpha:]]+) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:xdigit:]]{6})$"},

        {"Triangle", "^([[:alpha:]]+) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) "
                     "([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:xdigit:]]{6}) ([[:xdigit:]]{6})$"},

        {"Rectangle", "^([[:alpha:]]+) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) "
                      "([[:xdigit:]]{6}) ([[:xdigit:]]{6})$"},

        {"Circle", "^([[:alpha:]]+) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:d:]]+(.[[:d:]]+)?) ([[:xdigit:]]{6}) ([[:xdigit:]]{6})$"}
};

bool CShapeProcessor::HandleCommand(const std::string &commandLine)
{
    std::stringstream ss(commandLine);
    std::string action;
    ss >> action;
    if (auto it = shapes.find(action); it != shapes.end())
    {
        if (action == "LineSegment")
        {
            return CreateLineSegment(commandLine);
        }
        else if (action == "Triangle")
        {
            return CreateTriangle(commandLine);
        }
        else if (action == "Circle")
        {
            return CreateCircle(commandLine);
        }
        else if (action == "Rectangle")
        {
            return CreateRectangle(commandLine);
        }
    }
    else if (action == "minPerimeter")
    {
        PrintShapeWithMinPerimeter();
    }
    else if (action == "maxArea")
    {
        PrintShapeWithMaxArea();
    }
    else
    {
        return false;
    }
    return true;
}

std::smatch ParseInputString(const std::string& inputString)
{
    std::smatch matches;
    std::stringstream ss(inputString);
    std::string shapeName;
    ss >> shapeName;

    std::regex rx(shapes.find(shapeName)->second);
    regex_match(inputString, matches, rx);
    return matches;
}

bool CShapeProcessor::CreateLineSegment(const std::string &inputString)
{
    std::smatch matches = ParseInputString(inputString);
    if (matches.empty())
    {
        return false;
    }
    CPoint startPoint = {stod(matches[2]), stod(matches[4])};
    CPoint endPoint = {stod(matches[6]), stod(matches[8])};
    uint32_t outlineColor = stoul(matches[10], nullptr, 16);
    std::shared_ptr<IShape> lineSegment = std::make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
    m_shapesSet.push_back(lineSegment);
    return true;
}

bool CShapeProcessor::CreateTriangle(const std::string &inputString)
{
    std::smatch matches = ParseInputString(inputString);
    if (matches.empty())
    {
        return false;
    }
    CPoint vertex1 = {stod(matches[2]), stod(matches[4])};
    CPoint vertex2 = {stod(matches[6]), stod(matches[8])};
    CPoint vertex3 = {stod(matches[10]), stod(matches[12])};
    uint32_t outlineColor = stoul(matches[14], nullptr, 16);
    uint32_t fillColor = stoul(matches[15], nullptr, 16);
    std::shared_ptr<IShape> triangle = std::make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
    m_shapesSet.push_back(triangle);
    return true;
}

bool CShapeProcessor::CreateCircle(const std::string &inputString)
{
    std::smatch matches = ParseInputString(inputString);
    if (matches.empty())
    {
        return false;
    }
    CPoint center = {stod(matches[2]), stod(matches[4])};
    double radius = stod(matches[6]);
    uint32_t outlineColor = stoul(matches[8], nullptr, 16);
    uint32_t  fillColor = stoul(matches[9], nullptr, 16);
    std::shared_ptr<IShape> circle = std::make_shared<CCircle>(center, radius, outlineColor, fillColor);
    m_shapesSet.push_back(circle);
    return true;
}

bool CShapeProcessor::CreateRectangle(const std::string &inputString)
{
    std::smatch matches = ParseInputString(inputString);
    if (matches.empty())
    {
        return false;
    }
    CPoint UpperLeftPoint = {stod(matches[2]), stod(matches[4])};
    double width = stod(matches[6]);
    double height = stod(matches[8]);
    uint32_t outlineColor = stoul(matches[10], nullptr, 16);
    uint32_t fillColor = stoul(matches[11], nullptr, 16);
    std::shared_ptr<IShape> rectangle = std::make_shared<CRectangle>(UpperLeftPoint, width, height, fillColor, outlineColor);
    m_shapesSet.push_back(rectangle);
    return true;
}

void CShapeProcessor::PrintShapeWithMaxArea() const
{
    if (m_shapesSet.empty())
    {
        std::cout << "Список фигур пуст!" << std::endl;
        return;
    }
    auto shapeWithMaxArea = std::max_element(m_shapesSet.begin(), m_shapesSet.end(),[](const auto& shape1, const auto& shape2){
        return shape1->GetArea() < shape2->GetArea();
    });
    std::cout << (*shapeWithMaxArea)->ToString() << std::endl;
}

void CShapeProcessor::PrintShapeWithMinPerimeter() const
{
    if (m_shapesSet.empty())
    {
        std::cout << "Список фигур пуст!" << std::endl;
        return;
    }
    auto shapeWithMinPerimeter = std::min_element(m_shapesSet.begin(), m_shapesSet.end(),[](const auto& shape1, const auto& shape2){
        return shape1->GetPerimeter() < shape2->GetPerimeter();
    });
    std::cout << (*shapeWithMinPerimeter)->ToString() << std::endl;
}

void CShapeProcessor::DrawShapes() const
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Shapes", sf::Style::Default, settings);
    CCanvas canvas(window);
    while(window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color(255, 255, 255));
        for(const auto& item : m_shapesSet)
        {
            item->Draw(canvas);
        }
        window.display();
    }
}


