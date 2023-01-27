def testDecorator(callback):
    def innerFunc():
        print('test')
        callback(3, 70)
    return innerFunc

@testDecorator
def decoratedFunc(data, data2):
    print('test2', data, data2)

def main():
    decoratedFunc()

if __name__ == '__main__':
    main()