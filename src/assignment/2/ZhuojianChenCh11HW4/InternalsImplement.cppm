//export module storeshelf:internals;

#include "Internals.cppm"

namespace StoreShelf {
    double convertCmToIn(double cm) {
        return cm * 0.393701;
    }
}