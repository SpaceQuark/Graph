#ifndef WEDGE_HPP
#define WEDGE_HPP

template <typename V, typename W>
struct WEdge
{
    WEdge(V f, V t, V w)
        : from{f}, to{t}, weight{w} {}
    V from;
    V to;
    W weight;
};

#endif
