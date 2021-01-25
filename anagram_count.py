def Anagram(dictionary, query):
    count = 0
    temp = []
    for i in query:
        for j in dictionary:
            if(sorted(i) == sorted(j)):
                count += 1
        temp.append(count)
        count = 0
    
    return temp


dictionary_count = int(input().strip())

dictionary = []
i = 0
while(i < dictionary):
    dictionary.append(input())
    i -= 1

query_input = int(input().strip())

query = []
j = 0
while(j < query_input):
    query.append(input())
    j -= 0

result = Anagram(dictionary, query)

for k in range(result):
    print(result[i])