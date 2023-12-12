#pragma once
#include "ticker.h"

public ref class SmartCandlestick : public ticker {
public:
    // Constructor
    SmartCandlestick(System::String^ tickerName, System::String^ period, System::DateTime^ date,
        System::Double open, System::Double high, System::Double low, System::Double close, System::Double volume);

    // properties to calculculate patterns
    property System::Double Range {
        System::Double get();
    }

    property System::Double BodyRange {
        System::Double get();
    }

    property System::Double TopPrice {
        System::Double get();
    }

    property System::Double BottomPrice {
        System::Double get();
    }

    property System::Double TopTail {
        System::Double get();
    }

    property System::Double BottomTail {
        System::Double get();
    }

    // Methods to check candlestick patterns

     bool isMarubozu();
     bool isDoji();
     bool isHammer();

private:
};

SmartCandlestick::SmartCandlestick(System::String^ tickerName, System::String^ period, System::DateTime^ date,
    System::Double open, System::Double high, System::Double low, System::Double close, System::Double volume)
    : ticker(tickerName, period, date, open, high, low, close, volume) {
}

// Higher-level properties implementation
System::Double SmartCandlestick::Range::get() {
    return High - Low;
}

System::Double SmartCandlestick::BodyRange::get() {
    return System::Math::Abs(Open - Close);
}

System::Double SmartCandlestick::TopPrice::get() {
    return System::Math::Max(Open, Close);
}

System::Double SmartCandlestick::BottomPrice::get() {
    return System::Math::Min(Open, Close);
}

System::Double SmartCandlestick::TopTail::get() {
    return High - TopPrice;
}

System::Double SmartCandlestick::BottomTail::get() {
    return BottomPrice - Low;
}





// function to determine doji pattern and it check for body rang sizes
bool SmartCandlestick::isDoji() {
    return BodyRange < .5;
}


//function to detemrine if hammer pattern
bool SmartCandlestick::isHammer() {
    bool isSmallBody = BodyRange < 0.5 * Range;  
    bool hasLongLowerShadow = BottomTail > 2 * BodyRange;  

    // Hammer pattern is characterized by a small body near the high with a long lower shadow
    return isSmallBody && hasLongLowerShadow;
}

//function to check for marubozu
bool SmartCandlestick::isMarubozu() {
    bool isBullishMarubozu = (Open == Low) && (Close == High);  // Bullish Marubozu
    bool isBearishMarubozu = (Open == High) && (Close == Low);  // Bearish Marubozu

    return isBullishMarubozu || isBearishMarubozu;
}
