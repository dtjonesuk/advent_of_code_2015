//
// Created by David on 03/12/2023.
//

#include "Trip.h"
namespace day09 {

    int Trip::distance() {
        return std::transform_reduce(routes.begin(), routes.end(), 0, std::plus{}, [](auto &r) {
            return r.distance;
        });
    }

    void Trip::print(std::ostream &os) {
        for (auto &r: routes) {
            os << r.destination << " (" << r.distance << "), ";
        }
        os << "Total = " << distance() << std::endl;
    }
}