#include <vector>
#include "smartticker.h"


public ref class PatternRecognizer abstract
{
protected:
    int patternSize;
    System::String^ patternName;

public:
    PatternRecognizer(int size, System::String^ name)
    {
        patternSize = size;
        patternName = name;
    }
    System::String^ getName() {
    
        return patternName;
    }
    
    int getPatternSize() {
        return patternSize;
    }

    virtual System::Collections::Generic::List<int>^ RecognizePatterns(System::Collections::Generic::List<SmartCandlestick^>^ candlesticks)
    {
        System::Collections::Generic::List<int>^ foundIndices = gcnew System::Collections::Generic::List<int>();

        for (int i = 0; i <= candlesticks->Count - patternSize; i++)
        {
            System::Collections::Generic::List<SmartCandlestick^>^ sublist = gcnew System::Collections::Generic::List<SmartCandlestick^>(candlesticks->GetRange(i, patternSize));

            if (RecognizePattern(sublist))
            {
                for (int j = 0; j < patternSize; j++)
                {
                    foundIndices->Add(i + j);
                }
            }
        }

        return foundIndices;
    }

    virtual bool RecognizePattern(System::Collections::Generic::List<SmartCandlestick^>^ sublist) abstract;
};

public ref class DojiPatternRecognizer : public PatternRecognizer
{
public:
    DojiPatternRecognizer() : PatternRecognizer(1, "Doji") {}

    virtual bool RecognizePattern(System::Collections::Generic::List<SmartCandlestick^>^ sublist) override
    {
        return sublist[0]->isDoji();
    }
};


public ref class PeakPatternRecognizer : public PatternRecognizer
{
public:
    PeakPatternRecognizer() : PatternRecognizer(3, "Peak") {}

    virtual bool RecognizePattern(System::Collections::Generic::List<SmartCandlestick^>^ sublist) override
    {
        // Ensure that the sublist has enough elements for comparison
        if (sublist->Count < 3)
        {
            return false; // Not enough elements for comparison
        }

        // Compare the previous, current, and next candlesticks
        SmartCandlestick^ previousCandlestick = sublist[0];
        SmartCandlestick^ currentCandlestick = sublist[1];
        SmartCandlestick^ nextCandlestick = sublist[2];

        // Replace the following logic with your specific criteria for a "Peak" pattern
        if (currentCandlestick->High > previousCandlestick->High &&
            currentCandlestick->High > nextCandlestick->High)
        {
            
            return true;
        }

        return false;
    }
};



public ref class ValleyPatternRecognizer : public PatternRecognizer
{
public:
    ValleyPatternRecognizer() : PatternRecognizer(3, "Valley") {}

    virtual bool RecognizePattern(System::Collections::Generic::List<SmartCandlestick^>^ sublist) override
    {
        // Ensure that the sublist has enough elements for comparison
        if (sublist->Count < 3)
        {
            return false; // Not enough elements for comparison
        }

        // Compare the previous, current, and next candlesticks
        SmartCandlestick^ previousCandlestick = sublist[0];
        SmartCandlestick^ currentCandlestick = sublist[1];
        SmartCandlestick^ nextCandlestick = sublist[2];

        // Replace the following logic with your specific criteria for a "Peak" pattern
        if (currentCandlestick->Low < previousCandlestick->Low &&
            currentCandlestick->Low < nextCandlestick->Low)
        {

            return true;
        }

        return false;
    }
};


public ref class EngulfingPatternRecognizer : public PatternRecognizer
{
public:
    EngulfingPatternRecognizer() : PatternRecognizer(2, "Engulfing") {}

    virtual bool RecognizePattern(System::Collections::Generic::List<SmartCandlestick^>^ sublist) override
    {
        // Ensure that the sublist has enough elements for comparison
        if (sublist->Count < 2)
        {
            return false; // Not enough elements for comparison
        }

        // Compare the previous and current candlesticks
        SmartCandlestick^ previousCandlestick = sublist[0];
        SmartCandlestick^ currentCandlestick = sublist[1];

        // Check for a bullish engulfing pattern
        bool isBullishEngulfing = currentCandlestick->Close > previousCandlestick->Close &&
            currentCandlestick->Open < previousCandlestick->Open&&
            currentCandlestick->Close > currentCandlestick->Open;

        // Check for a bearish engulfing pattern
        bool isBearishEngulfing = currentCandlestick->Close < previousCandlestick->Close&&
            currentCandlestick->Open > previousCandlestick->Open &&
            currentCandlestick->Close < currentCandlestick->Open;

        return isBullishEngulfing || isBearishEngulfing;
    }
};

public ref class HammerPatternRecognizer : public PatternRecognizer
{
public:
    HammerPatternRecognizer() : PatternRecognizer(1, "Hammer") {}

    virtual bool RecognizePattern(System::Collections::Generic::List<SmartCandlestick^>^ sublist) override
    {
        return sublist[0]->isHammer();
    }
};

public ref class MarubozuPatternRecognizer : public PatternRecognizer
{
public:
    MarubozuPatternRecognizer() : PatternRecognizer(1, "Marubozu") {}

    virtual bool RecognizePattern(System::Collections::Generic::List<SmartCandlestick^>^ sublist) override
    {
        return sublist[0]->isHammer();
    }
};

public ref class HaramiPatternRecognizer : public PatternRecognizer
{
public:
    HaramiPatternRecognizer() : PatternRecognizer(2, "Harami") {}

    virtual bool RecognizePattern(System::Collections::Generic::List<SmartCandlestick^>^ sublist) override
    {
        // Ensure that the sublist has enough elements for comparison
        if (sublist->Count < 2)
        {
            return false; // Not enough elements for comparison
        }

        // Compare the previous and current candlesticks
        SmartCandlestick^ previousCandlestick = sublist[0];
        SmartCandlestick^ currentCandlestick = sublist[1];

        // Check for a bullish harami pattern
        bool isBullishHarami = currentCandlestick->Close < previousCandlestick->Open&&
            currentCandlestick->Open > previousCandlestick->Close &&
            currentCandlestick->Close < previousCandlestick->Close&&
            currentCandlestick->Open > previousCandlestick->Open;

        // Check for a bearish harami pattern
        bool isBearishHarami = currentCandlestick->Close > previousCandlestick->Open &&
            currentCandlestick->Open < previousCandlestick->Close&&
            currentCandlestick->Close > previousCandlestick->Close &&
            currentCandlestick->Open < previousCandlestick->Open;

        return isBullishHarami || isBearishHarami;
    }
};