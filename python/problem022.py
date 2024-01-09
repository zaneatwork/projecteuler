# Using names.txt, a 46K text file containing over five-thousand first names,
# begin by sorting it into alphabetical order. Then working out the
# alphabetical value for each name, multiply this value by its alphabetical
# position in the list to obtain a name score.

# For example, when the list is sorted into alphabetical order, COLIN, which is
# worth 3+15+12+9+14 = 53, is the 938th name in the list. So, COLIN would
# obtain a score of 938 x 53 = 49714.

# What is the total of all the name scores in the file?


names = []
with open("../data_files/names.txt", "r") as name_file:
    names = sorted(
        name_file.read().replace('"', "").replace("\n", "").split(",")
    )

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
total_scores = sum(
    [
        sum([alphabet.index(char) + 1 for char in list(name)]) * (index + 1)
        for index, name in enumerate(names)
    ]
)

print(total_scores)
