class Foo {
    std::atomic<int> turn = 1;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        while(turn!=1)
            this_thread::yield();
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn++;
    }

    void second(function<void()> printSecond) {
        while(turn!=2)
            this_thread::yield();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        turn++;
    }

    void third(function<void()> printThird) {
        while(turn!=3)
            this_thread::yield();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};