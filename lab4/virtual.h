#ifndef VIRTUAL
#define VIRTUAL

class IGeoFig{
public:
    virtual double Square() = 0;
    virtual double Perimeter() = 0;
};

class Vector2D{
public:
    double x, y;
};

class IPhysObj{
public:
    virtual double Mass() = 0;
    virtual Vector2D Position() = 0;
    virtual bool operator==(IPhysObj & obj) = 0;
    virtual bool operator<(IPhysObj & obj) = 0;
};

class IPrintable{
public:
    virtual void Draw() = 0;
};

class IDiagInitable{
public:
    virtual void InitFromDiag(Vector2D coord1, Vector2D coord2) = 0;
};

class BaseObj{
public:
    virtual unsigned int size() = 0;
    virtual const char* classname() = 0;
};

class Interface: public IPhysObj, public BaseObj, public IGeoFig, public IDiagInitable{};

class LineSegment: public Interface{
private:
    Vector2D point1{};
    Vector2D point2{};
public:
    LineSegment();
    ~LineSegment();
    LineSegment(Vector2D coord1, Vector2D coord2);
    void InitFromDiag(Vector2D coord1, Vector2D coord2) override;
    double Square() override;
    double Perimeter() override;
    const char* classname() override;
    unsigned int size() override;
    double Mass() override;
    Vector2D Position() override;
    bool operator==(IPhysObj & obj) override;
    bool operator<(IPhysObj & obj) override;
};


class Trapezoid: public Interface{
private:
    Vector2D point1{};
    Vector2D point2{};
    Vector2D point3{};
    Vector2D point4{};
public:
    Trapezoid();
    ~Trapezoid();
    Trapezoid(Vector2D coord1, Vector2D coord2, Vector2D coord3, Vector2D coord4);
    double Square() override;
    double Perimeter() override;
    const char* classname() override;
    unsigned int size() override;
    double Mass() override;
    Vector2D Position() override;
    bool operator==(IPhysObj & obj) override;
    bool operator<(IPhysObj & obj) override;
    void InitFromDiag(Vector2D coord1, Vector2D coord2) override;
};

#endif