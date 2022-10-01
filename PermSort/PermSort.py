ZERO_DATA = list()


def perm_sort(data: list, variants: list) -> list:
    if len(variants) == 1:
        if is_sorted(data + variants):
            return data + variants
        return ZERO_DATA
    for i in variants:
        temp = variants.copy()
        temp.remove(i)
        result = perm_sort(data + [i], temp)
        if result != ZERO_DATA:
            return result
    return ZERO_DATA


def is_sorted(data: list) -> bool:
    for i in range(len(data) - 1):
        if data[i + 1] < data[i]:
            return False
    return True


def main():
    data = [3, 2, 5, -5, 8, 9, -11]
    data_sorted = perm_sort([], data)
    print(*data_sorted)


if __name__ == '__main__':
    main()
