#pragma once

public ref class ticker {
public:
    ticker(System::String^ tickerName, System::String^ period, System::DateTime^ date,
        System::Double open, System::Double high, System::Double low, System::Double close, System::Double volume);

    // Properties 
    property System::String^ TickerName {
        System::String^ get() { return tickerName; }
        void set(System::String^ value) { tickerName = value; }
    }

    property System::String^ Period {
        System::String^ get() { return period; }
        void set(System::String^ value) { period = value; }
    }

    property System::DateTime^ Date {
        System::DateTime^ get() { return date; }
        void set(System::DateTime^ value) { date = value; }
    }

    property System::Double Open {
        System::Double get() { return open; }
        void set(System::Double value) { open = value; }
    }

    property System::Double High {
        System::Double get() { return high; }
        void set(System::Double value) { high = value; }
    }

    property System::Double Low {
        System::Double get() { return low; }
        void set(System::Double value) { low = value; }
    }

    property System::Double Close {
        System::Double get() { return close; }
        void set(System::Double value) { close = value; }
    }

    property System::Double Volume {
        System::Double get() { return volume; }
        void set(System::Double value) { volume = value; }
    }

private:
    System::String^ tickerName;
    System::String^ period;
    System::DateTime^ date;
    System::Double open;
    System::Double high;
    System::Double low;
    System::Double close;
    System::Double volume;
};

// Constructor 
ticker::ticker(System::String^ tickerName, System::String^ period, System::DateTime^ date,
    System::Double open, System::Double high, System::Double low, System::Double close, System::Double volume)
    : tickerName(tickerName), period(period), date(date), open(open), high(high), low(low), close(close), volume(volume) {

}