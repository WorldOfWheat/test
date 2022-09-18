function getSum(x)
    
    if (x == 0) then
        return 0
    end

    return (x + getSum(x-1))

end

print(getSum(1000))