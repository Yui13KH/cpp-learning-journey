#include "Utility.h"

enum Overlap { NoOverlap = 1, PartialOverlap, FullOverlap };

Overlap checkOverlap(strPeriod period1, strPeriod period2) {
    // Compare start and end dates of both periods
    DateComparison startComparison =
        Utility::compareDates(period1.start, period2.end);  // p1.start vs p2.end
    DateComparison endComparison =
        Utility::compareDates(period1.end, period2.start);  // p1.end vs p2.start

    // No overlap case: p1 starts after p2 ends OR p1 ends before p2 starts
    if (startComparison == LATER || endComparison == EARLIER) {
        return NoOverlap;
    }

    // Full overlap case: p1 fully contains p2 or vice versa
    if (Utility::compareDates(period1.start, period2.start) != LATER &&
        Utility::compareDates(period1.end, period2.end) != EARLIER) {
        return FullOverlap;
    }
    if (Utility::compareDates(period2.start, period1.start) != LATER &&
        Utility::compareDates(period2.end, period1.end) != EARLIER) {
        return FullOverlap;
    }

    // Otherwise, it's a partial overlap
    return PartialOverlap;
}

void printOverlap(Overlap overlap) {
    switch (overlap) {
        case NoOverlap:
            std::cout << "No overlap." << std::endl;
            break;
        case PartialOverlap:
            std::cout << "Partial overlap." << std::endl;
            break;
        case FullOverlap:
            std::cout << "Full overlap." << std::endl;
            break;
    }
}

int main() {
    strPeriod period1 = Utility::readPeriod("Enter period 1: ");
    strPeriod period2 = Utility::readPeriod("Enter period 2: ");

    Overlap overlap = checkOverlap(period1, period2);
    printOverlap(overlap);

    return 0;
}