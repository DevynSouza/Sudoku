class logicError {
    private:
        const char* errorType;
    public: 
        logicError(char* error);

};

class streamError { //Handles stream probbaly mostly stdout and stdin
    private:
        const char* errorType;

    public:
        streamError(char* error);
        void badGameType();

};