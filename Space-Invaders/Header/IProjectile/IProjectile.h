#pragma once


namespace Element
{
    class IProjectile
    {
    public:
        virtual ~IProjectile() = default;

        virtual void initialize() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void destroy() = 0;
    };
}
