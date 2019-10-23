from nltk.chat.util import Chat, reflections

pairs = [
    [
        r"my name is (.*)",
        ["Hello %1, How are you today ?",]
    ],
     [
        r"what is your name ?",
        ["My name is Chatty and I'm a chatbot ?",]
    ],
    [
        r"how are you ?",
        ["I'm doing good\nHow about You ?",]
    ],
    [
        r"sorry (.*)",
        ["Its alright","Its OK, never mind",]
    ],
    [
        r"i'm (.*) good",
        ["Nice to hear that","Alright :)",]
    ],
    [
        r"hi|hey|hello",
        ["Hello", "Hey there",]
    ],
    [
        r"(.*) investment options (.*)",
        ["1.Mutual Funds\n2.National Pension Scheme\n3.Public Provident Fund\n4. Real Estate Investment"]
    ],
    [
        r"(.*) mutual funds (.*)",
        ["These are considered to be one of the best avenues for investment in our country."]
    ],
    [
        r"(.*) national pension scheme (.*)",
        ["The NPS is a government-sponsored scheme that is one of the best modes of investment for those with a very low-risk profile."]
    ],
    [
        r"(.*) public provident fund (.*)",
        ["If you are a risk-averse investor, the Public Provident Fund (PPF) could be the one for you."]
    ],
    [
        r"(.*) real estate investment (.*)",
        ["Real estate is a good investment option for those who have abundant money in hand."]
    ],
    [
        r"(.*) created ?",
        ["Student",]
    ],
    [
        r"(.*) (location|city) ?",
        ['Pune, Maharashtra',]
    ],
    [
        r"how is weather in (.*)?",
        ["Weather in %1 is awesome like always","Too hot man here in %1","Too cold man here in %1","Never even heard about %1"]
    ],
    [
        r"how much experienced are you?",
        ["I am AI powered i'm ahead of everyone.",]
    ],
    [
        r"which (.*) stock ?",
        ["Reliance"]
    ],
    [
        r"is (liquid|equity) safe (.*)?",
        ["Yes"]
    ],
    [
        r"quit",
        ["BBye take care. See you soon :) ","It was nice talking to you. See you soon :) for more investment advice"]
    ],
]
def chatty():
        print("Hi, I'm Chatty and I chat alot ;)\nPlease type lowercase English language to start a conversation. Type quit to leave ") #default message at the start
        chat = Chat(pairs,reflections)
        chat.converse()
if __name__ == "__main__":
    chatty()