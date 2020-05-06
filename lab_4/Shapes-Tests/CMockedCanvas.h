#include "../Shapes/ICanvas.h"
#include <string>
#include <vector>
class CMockedCanvas : public ICanvas
{
public:
    void DrawLine(CPoint from, CPoint to, uint32_t lineColor) override;
    void FillPolygon(std::vector<CPoint> points, uint32_t fillColor) override;
    void DrawCircle(CPoint center, double radius, uint32_t lineColor) override;
    void FillCircle(CPoint center, double radius, uint32_t fillColor) override;
    [[nodiscard]] std::vector<std::string> GetActionHistory() const;

private:
    std::vector<std::string> m_actionHistory;
};



