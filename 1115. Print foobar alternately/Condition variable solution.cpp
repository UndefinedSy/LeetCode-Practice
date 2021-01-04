class FooBar {
private:
    int n;
    bool FooFinished;
    std::mutex m;
    std::condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        FooFinished = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [&]{return !FooFinished;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();

            FooFinished = true;
            lk.unlock();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [&]{return FooFinished;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            FooFinished = false;
            lk.unlock();
            cv.notify_one();
        }
    }
};