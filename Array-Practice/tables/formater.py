import json

def format_input(data):
    result = []
    for line in data:
        line = line.split('\t')
        line[-1] = line[-1].strip()
        line.insert(0, line[0][0])
        if line:
            result.append(tuple(line))
    return result

def input(file_name):
    result = []
    with open(file_name) as f:
        result = f.readlines()
    return result

def convert_to_json(data):
    result = []
    print(json.dumps(data, sort_keys=True, indent=4))

def main():
    # for table in {'一級簡碼.txt', '二級簡碼.txt', '特別碼.txt'}:
    for table in {'特別碼.txt'}:
        table_data = input(table)
        table_data = format_input(table_data)
        convert_to_json(table_data)
        # print(table_data)


if __name__ == '__main__':
    main()