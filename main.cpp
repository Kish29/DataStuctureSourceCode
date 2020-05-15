#include <iostream>
#include <string>
#include <vector>
// Solution1 namespace
namespace Solution1 {
    using std::string;

    // define the data type
    class phoneNumber {
    public:
        phoneNumber();  // default constructor

        ~phoneNumber();

        string getPhoneNumber() const;      // get value

        void putValueIn(const string &phoneNumber);     // input data (assignment)

    private:
        string *numberValue;
    };

    phoneNumber::phoneNumber() {
        this->numberValue = new string("0");    // set value to 0 by default
    }

    phoneNumber::~phoneNumber() {
        // release memory
        delete (this->numberValue);
    }

    string phoneNumber::getPhoneNumber() const {
        return *this->numberValue;  // * to get value instead of address
    }

    void phoneNumber::putValueIn(const string &phoneNumber) {
        *this->numberValue = phoneNumber;
    }

// define the max number for one array cause to dynamic applying for
    const int MAXcallNum = 1024;

    class callHistory {
    public:
        // default constructor initializes its three arrays
        callHistory();

        ~callHistory();

        // define input function
        void dataInsert(const int &flag, const string &phoneNumber);

        // show all the datas
        void showCallHistory() const;

    private:
        phoneNumber *missedCalls;
        int misIndx = 0;
        // index store the position which current data should be inserted in
        phoneNumber *receivedCalls;
        int rcvIndx = 0;
        phoneNumber *dialedCalls;
        int dldIndx = 0;
    };

    callHistory::callHistory() {
        this->missedCalls = new phoneNumber[MAXcallNum]();
        this->receivedCalls = new phoneNumber[MAXcallNum]();
        this->dialedCalls = new phoneNumber[MAXcallNum]();
    }

    callHistory::~callHistory() {
        // release memories which had been dynamically applied
        delete[](this->missedCalls);
        delete[](this->receivedCalls);
        delete[](this->dialedCalls);
    }

    void callHistory::dataInsert(const int &flag, const string &phoneNumber) {
        switch (flag) {     // according to the value of flag
            case 0:
                this->missedCalls[this->misIndx++].putValueIn(phoneNumber);
                break;
            case 1:
                this->receivedCalls[this->rcvIndx++].putValueIn(phoneNumber);
                break;
            default:
                this->dialedCalls[this->dldIndx++].putValueIn(phoneNumber);
                break;
        }
    }

    void callHistory::showCallHistory() const {
        for (int index = 0; index < 10; ++index) {
            std::cout << this->missedCalls[index].getPhoneNumber() << " "
                      << this->receivedCalls[index].getPhoneNumber() << " "
                      << this->dialedCalls[index].getPhoneNumber() << std::endl;
        }
    }
}

namespace Solution2 {
    // define data type in order to change anytime
    template<class dataType>

    // simulation stack working styles
    class magicStack {
    public:
        // constructor set to explicit
        magicStack() = default;

        explicit magicStack(const int &N);

        ~magicStack();

        // judge the stack whether empty
        bool stackIsEmpty() const;

        // judge the stack whether be filled
        bool stackIsFull() const;

        // push
        void pushElement(const dataType &data);

        // pop back, don't change the index, used for judgement
        dataType popBack() const;

        // pop
        dataType popElement();

        // get stack scale
        int getStackScale();

    protected:
        dataType *virtualStack{};
        int saveScale{};
        int index{};
    };

    template<class dataType>
    magicStack<dataType>::magicStack(const int &N) {
        this->saveScale = N;    // store the scale
        this->virtualStack = new dataType[this->saveScale]();   // initialize all element to 0
        this->index = 0;
    }

    template<class dataType>
    magicStack<dataType>::~magicStack() {
        //release memory
        delete[] (this->virtualStack);
    }

    // if stack is empty, return true, or return false
    template<class dataType>
    bool magicStack<dataType>::stackIsEmpty() const {
        return (this->index == 0) && (this->virtualStack[0] == 0);
    }

    // if stack is full, return true, or return false
    template<class dataType>
    bool magicStack<dataType>::stackIsFull() const {
        return index == this->saveScale + 1;
    }

    template<class dataType>
    void magicStack<dataType>::pushElement(const dataType &data) {
        this->virtualStack[this->index++] = data;
    }

    // this function do not change the value of index
    template<class dataType>
    dataType magicStack<dataType>::popBack() const {
        return this->virtualStack[this->index - 1];
    }

    template<class dataType>
    dataType magicStack<dataType>::popElement() {
        auto tmp = this->virtualStack[this->index - 1];
        this->virtualStack[this->index - 1] = 0;
        index--;
        return tmp;
    }

    template<class dataType>
    int magicStack<dataType>::getStackScale() {
        return this->saveScale;
    }

    // define solution algorithm            // here must set variable ---> stack to be preference type
    template<class dataType>
    std::string solutionAlgorithm1(magicStack<dataType> &stack, const dataType example[]) {
        // cause the swap parameter of class, call ~magicStack function will due to
        // over address access
        auto examplePtr = example;  // get example array's first address
        auto tmp1 = stack.getStackScale();      // get stack value
        auto tmp2 = tmp1 - 1;       // tmp2 set to be the circulate times
        bool flag = false;      //flag set to false by default
        while (tmp2 != -1) {
            dataType currentValue = tmp1 - tmp2;    // the value every turn will be pushed in stack
            stack.pushElement(currentValue);
            // if current push value equals to the example array's element
            while (stack.popBack() == *examplePtr && !stack.stackIsEmpty()) {
                stack.popElement(); // pop current element
                examplePtr++;       // get the next value
            }
            tmp2--;
        }
        // if now the stack is not empty, indicate that the example is not achieve
        flag = stack.stackIsEmpty();
        return flag ? "YES" : "NO";
    }

    // define the solution algorithm
    template<class dataType>
    bool solutionAlgorithm2(magicStack<dataType> &stack, const dataType example[]) {
        // get example's first address
        auto examplePtr = example;
        // push all data in stack
        while (*examplePtr != '@') {
            stack.pushElement(*examplePtr++);
        }

        // restore to circulate
        examplePtr = example;
        while (stack.popBack() == *examplePtr++)
            stack.popElement();
        // if while circle run out, and the *--example is '@', indicate that pop string equals to original one
        return *--examplePtr == '@';    // cause examplePtr additionally offset 1
    }
}

namespace Solution3 {

    // important! this struct define the operator priority

    typedef struct operatorPriority {
        int thisPriority{};
        char thisCharacter{};
    } oprtprt;

    // use the stack type defined by myself
    using Solution2::magicStack;

    // inherit from stack defined by myself
    template<class dadaType>
    class reversePolishNotation : public magicStack<dadaType> {
    public:
        explicit reversePolishNotation(const int &N);

        ~reversePolishNotation();

        // get priority by character
        int getPriorityBycharacter(char inputchar);

        // judge every new operator
        void operatorPushIn(char oprt);

        // get reverse polish notation
        void getReversePolishNotation(const std::string &examplestring);

        // get final result
        int getResultOfPolishNotation();

    private:
        // define the struct operator priority
        oprtprt *oprtHashArray{};      // initialize the operator priority

        // store the Polish Notation
        std::string polishNotation{};
    };

    template<class dataType>
    reversePolishNotation<dataType>::reversePolishNotation(const int &N) {

        this->oprtHashArray = new oprtprt[5];    // six operator: + - * / ( , ')' ignored in this hash map
        this->oprtHashArray[0].thisCharacter = '(';
        this->oprtHashArray[0].thisPriority = 0;    // set the lowest priority
        this->oprtHashArray[1].thisCharacter = '+';
        this->oprtHashArray[1].thisPriority = 1;
        this->oprtHashArray[2].thisCharacter = '-';
        this->oprtHashArray[2].thisPriority = 1;
        this->oprtHashArray[3].thisCharacter = '*';
        this->oprtHashArray[3].thisPriority = 2;
        this->oprtHashArray[4].thisCharacter = '/';
        this->oprtHashArray[4].thisPriority = 2;
        this->virtualStack = new dataType[N]();
        this->index = 0;
        this->saveScale = N;
    }

    template<class dataType>
    reversePolishNotation<dataType>::~reversePolishNotation() {
        // release memories
        delete[](this->oprtHashArray);
        // pay attention here!!! -----DO NOT DELETE!!!----- FATHER'S virtualStack, virtualStack will be delete by father,
        // otherwise it will cause memory problem
        // father's constructor can not inherit, but destructor will invoke after children's destructor
    }


    template<class dadaType>
    void reversePolishNotation<dadaType>::getReversePolishNotation(const std::string &examplestring) {
        // judge for every single character
        for (char ch: examplestring) {
            if (ch >= '0' && ch <= '9')
                this->polishNotation.append(1, ch);
            else
                operatorPushIn(ch);
        }
        // pop all the leftover
        while (!this->stackIsEmpty()) {
            this->polishNotation.append(1, this->popElement());
        }
    }

    template<class dataType>
    int reversePolishNotation<dataType>::getResultOfPolishNotation() {
        magicStack<int> numberstack(20);
        for (char c: this->polishNotation) {
            if (c == '+')
                numberstack.pushElement(numberstack.popElement() + numberstack.popElement());
            else if (c == '-')
                numberstack.pushElement(numberstack.popElement() - numberstack.popElement());
            else if (c == '*')
                numberstack.pushElement(numberstack.popElement() * numberstack.popElement());
            else if (c == '/') {
                int tmp = numberstack.popElement();
                numberstack.pushElement(numberstack.popElement() / tmp);
            } else  // if number, push it in
                numberstack.pushElement(c - '0');
        }
        return numberstack.popElement();
    }

    template<class dadaType>
    void reversePolishNotation<dadaType>::operatorPushIn(char oprt) {
        // if stack is empty or current operator's priority value than last one, push it in the stack
        if (this->stackIsEmpty() || oprt == '(' ||  // when operator is '(', push it in stack right away
            getPriorityBycharacter(oprt) > getPriorityBycharacter(this->popBack())) {
            this->pushElement(oprt);
            return;
        }
            // if current operator is ')', pop all the operators until the '('
        else if (oprt == ')') {
            while (this->popBack() != '(')
                this->polishNotation.append(1, this->popElement());
            this->popElement(); // pop the '('
            return;
        } else if (getPriorityBycharacter(oprt) <= getPriorityBycharacter(this->popBack())) {
            // if current operator's priority less than last one
            this->polishNotation.append(1, this->popElement());
            operatorPushIn(oprt);   // pop last one util current one's priority greater than the later or stack is empty
        }
    }

    template<class dadaType>
    int reversePolishNotation<dadaType>::getPriorityBycharacter(char inputchar) {
        for (int index = 0; index < 6; index++) {
            if (inputchar == this->oprtHashArray[index].thisCharacter)
                return this->oprtHashArray[index].thisPriority;     // get input character's priority
        }
        return -1;
    }
}

namespace Solution4_1 {
    template<class dataType>
    class matrixChange {
    public:
        explicit matrixChange(const int &N, const int &M);

        ~matrixChange();

        // function for matrix assignment
        void matrixElementAssignment();

        // function for addressing the instructors
        void matrixReadChangeInstructors(const int &rowOrcolumn, const int &para1, const int &para2);

        // function for row change
        void matrixChangeRow(const int &row1, const int &row2);

        // function for column change
        void matrixChangeColumn(const int &column1, const int &column2);

        // function to print this matrix
        void matrixToShow() const;

    private:
        int row, column; // define the matrix scale
        dataType **matrixForChange;  // define an array for two dimension
        int columnRecorder[100001]{};   // creat a new array to store the change of columns
    };

    template<class dataType>
    matrixChange<dataType>::matrixChange(const int &N, const int &M) : row(N), column(M) {
        try {
            this->matrixForChange = new dataType *[this->row]();
        }
        catch (const std::bad_alloc &exception) {
            std::cerr << "row too big, bad allocation!";
            exit(-1);
        }
        for (int index = 0; index < this->row; index++) {
            try {
                this->matrixForChange[index] = new dataType[this->column]();   // initial this array
            }
            catch (const std::bad_alloc &exception) {
                std::cerr << "column too big, bad allocation!";
                exit(-1);
            }
        }
    }

    template<class dataType>
    matrixChange<dataType>::~matrixChange() {
        for (int index = 0; index < this->row; index++)     // release array according to row numbers
            delete[](this->matrixForChange[index]);
    }

    template<class dataType>
    void matrixChange<dataType>::matrixChangeRow(const int &row1, const int &row2) {
        // algorithm for swapping two rows
        dataType *tmpPtr = this->matrixForChange[row1 - 1];     // saving the the former row's first address
        this->matrixForChange[row1 - 1] = this->matrixForChange[row2 - 1];
        this->matrixForChange[row2 - 1] = tmpPtr;
    }

    template<class dataType>
    void matrixChange<dataType>::matrixChangeColumn(const int &column1, const int &column2) {
        // just change the record array
        int tmp = this->columnRecorder[column1 - 1];
        this->columnRecorder[column1 - 1] = this->columnRecorder[column2 - 1];
        this->columnRecorder[column2 - 1] = tmp;
    }

    template<class dataType>
    void matrixChange<dataType>::matrixToShow() const {
        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < this->column; j++) {
                std::cout << this->matrixForChange[i][this->columnRecorder[j]];
                if (j == this->column - 1)
                    std::cout << std::endl;
                else
                    std::cout << " ";
            }
    }

    template<class dataType>
    void
    matrixChange<dataType>::matrixReadChangeInstructors(const int &rowOrcolumn, const int &para1, const int &para2) {
        if (rowOrcolumn)    // if rowOrcolumn == 1, change column
            this->matrixChangeColumn(para1, para2);
        else
            this->matrixChangeRow(para1, para2);
    }

    template<class dataType>
    void matrixChange<dataType>::matrixElementAssignment() {
        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < this->column; j++) {
                this->columnRecorder[j] = j;
                std::cin >> this->matrixForChange[i][j];
            }
    }

}
namespace Solution4_2 {
    using std::vector;
    vector<int> array[10000];

    void setFoundation(const int &scale) {
        // set foundation's value from 1 to scale
        for (int i = 0; i < scale; i++) {
            array[i].push_back(i + 1);
        }
    }

    void buildingBlocks(int para1, int para2) {
        if (array[para2 - 1].empty() || para1 == para2)
            return;
        for (int i = 0; i < array[para2 - 1].size(); i++)
            array[para1 - 1].push_back(array[para2 - 1][i]);
        array[para2 - 1].clear();   // empty stack's datas
        vector<int>().swap(array[para2 - 1]);   // release stack's memory
    }

    void showBuidedBlocks(const int &scale) {
        for (int i = 0; i < scale; i++) {
            if (array[i].empty())
                std::cout << std::endl;
            else {
                for (int j : array[i])
                    std::cout << j << " ";
                std::cout << std::endl;
            }
        }
    }
}

int main(int argc, char *argv[], char *envp[]) {
    using namespace Solution4_2;
    int scale, operations;
    std::cin >> scale >> operations;
    setFoundation(scale);
    int para1, para2;
    for (int i = 0; i < operations; ++i) {
        std::cin >> para1 >> para2;
        buildingBlocks(para1, para2);
    }
    showBuidedBlocks(scale);
    return 0;
}
