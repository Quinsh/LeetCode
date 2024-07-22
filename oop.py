# LAB 7 - OOP

# Q3 ___________________________________________________________________________

# class Account:
#     max_withdrawal = 10
#     interest = 0.02

#     def __init__(self, account_holder):
#         self.balance = 0
#         self.holder = account_holder

#     def deposit(self, amount):
#         self.balance = self.balance + amount
#         return self.balance

#     def withdraw(self, amount):
#         if amount > self.balance:
#             return "Insufficient funds"
#         if amount > self.max_withdrawal:
#             return "Can't withdraw that amount"
#         self.balance = self.balance - amount
#         return self.balance
    
#     def time_to_retire(self, amount):
#         """Return the number of years until balance would grow to amount."""
#         assert self.balance > 0 and amount > 0 and self.interest > 0
#         years = 0
#         bal = self.balance
#         while (bal < amount):
#             years += 1
#             bal *= (1+self.interest)
#         return years
    
# a = Account('John')
# print(a.deposit(10))  # 10
# print(a.balance)  # 10
# print(a.interest)  # 0.02
# print(a.time_to_retire(10.25))  # 2
# print(a.balance)  # 10
# print(a.time_to_retire(11))  # 5
# print(a.time_to_retire(100))  # 117



# Q4 ___________________________________________________________________________

# class FreeChecking(Account):
#     """A bank account that charges for withdrawals, but the first two are free!
#     >>> ch = FreeChecking('Jack')
#     >>> ch.balance = 20
#     >>> ch.withdraw(100)  # First one's free. Still counts as a free withdrawal even though it was unsuccessful
#     'Insufficient funds'
#     >>> ch.withdraw(3)    # Second withdrawal is also free
#     17
#     >>> ch.balance
#     17
#     >>> ch.withdraw(3)    # Ok, two free withdrawals is enough, as free_withdrawals is only 2
#     13
#     >>> ch.withdraw(3)
#     9
#     >>> ch2 = FreeChecking('John')
#     >>> ch2.balance = 10
#     >>> ch2.withdraw(3) # No fee
#     7
#     >>> ch.withdraw(3)  # ch still charges a fee
#     5
#     >>> ch.withdraw(5)  # Not enough to cover fee + withdraw
#     'Insufficient funds'
#     """
#     withdraw_fee = 1
#     free_withdrawals = 2

#     "*** YOUR CODE HERE ***"
#     def withdraw(self, amount):
#         if self.free_withdrawals:
#             self.free_withdrawals -= 1
#             return super().withdraw(amount)
#         else:
#             self.balance -= self.withdraw_fee # the fee is always decremented
#             return super().withdraw(amount)

# ch = FreeChecking('Jack')
# ch.balance = 20
# print(ch.withdraw(100))  # 'Insufficient funds'
# print(ch.withdraw(3))    # 17
# print(ch.balance)  # 17
# print(ch.withdraw(3))    # 13
# print(ch.withdraw(3))    # 9
# ch2 = FreeChecking('John')
# ch2.balance = 10
# print(ch2.withdraw(3))  # 7
# print(ch.withdraw(3))  # 5
# print(ch.withdraw(5))  # 'Insufficient funds'



# Q5 ___________________________________________________________________________

# class Transaction:
#     def __init__(self, id, before, after):
#         self.id = id
#         self.before = before
#         self.after = after

#     def changed(self):
#         return self.before != self.after

#     def report(self):
#         msg = 'no change'
#         if self.changed():
#             if self.after > self.before:
#                 msg = f"increased {self.before}->{self.after}"
#             else:
#                 msg = f"decreased {self.before}->{self.after}"

#         return str(self.id) + ': ' + msg

# class BankAccount:

#     def __init__(self, account_holder):
#         self.balance = 0
#         self.holder = account_holder
#         self.id = 1
#         self.transactions = []

#     def deposit(self, amount):
#         """Increase the account balance by amount, add the deposit
#         to the transaction history, and return the new balance.
#         """
#         before = self.balance
#         self.balance = self.balance + amount

#         # create transaction and add to the list
#         t = Transaction(self.id, before, self.balance)
#         self.id += 1
#         self.transactions.append(t)

#         return self.balance

#     def withdraw(self, amount):
#         """Decrease the account balance by amount, add the withdraw
#         to the transaction history, and return the new balance.
#         """
#         if amount > self.balance:
#             self.transactions.append(Transaction(self.id, self.balance, self.balance))
#             self.id += 1
#             return 'Insufficient funds'
        
#         before = self.balance
#         self.balance = self.balance - amount

#         # create transaction and add to the list
#         t = Transaction(self.id, before, self.balance)
#         self.id += 1
#         self.transactions.append(t)

#         return self.balance
    

# a = BankAccount('Eric')
# print(a.deposit(100))    # 100
# b = BankAccount('Erica')
# print(a.withdraw(30))    # 70
# print(a.deposit(10))     # 80
# print(b.deposit(50))     # 50
# print(b.withdraw(10))    # 40
# print(a.withdraw(100))   # 'Insufficient funds'
# print(len(a.transactions))  # 4
# print(len([t for t in a.transactions if t.changed()]))  # 3
# for t in a.transactions:
#     print(t.report())
# # Expected output:
# # 0: increased 0->100
# # 1: decreased 100->70
# # 2: increased 70->80
# # 3: no change

# print(b.withdraw(100))   # 'Insufficient funds'
# print(b.withdraw(30))    # 10
# for t in b.transactions:
#     print(t.report())
# # Expected output:
# # 0: increased 0->50
# # 1: decreased 50->40
# # 2: no change
# # 3: decreased 40->10



# Q6 ___________________________________________________________________________


# class Email:
#     def __init__(self, msg, sender: 'Client', recipient_name: str):
#         self.msg = msg
#         self.sender = sender
#         self.recipient_name = recipient_name

# class Server:
#     """Each Server has one instance attribute called clients that is a
#     dictionary from client names to client objects.
#     """
#     def __init__(self):
#         self.clients = {}

#     def send(self, email):
#         """Append the email to the inbox of the client it is addressed to.
#             email is an instance of the Email class.
#         """
#         self.clients[email.recipient_name].inbox.append(email)

#     def register_client(self, client: 'Client'):
#         """Add a client to the clients mapping (which is a 
#         dictionary from client names to client instances).
#             client is an instance of the Client class.
#         """
#         self.clients[client.name] = client

# class Client:
#     def __init__(self, server, name):
#         self.inbox = []
#         self.server = server
#         self.name = name
#         server.register_client(self)

#     def compose(self, message, recipient_name):
#         """Send an email with the given message to the recipient."""
#         email = Email(message, self, recipient_name)
#         self.server.send(email)

# s = Server()
# a = Client(s, 'Alice')
# b = Client(s, 'Bob')
# a.compose('Hello, World!', 'Bob')
# print(b.inbox[0].msg)  # 'Hello, World!'
# a.compose('CS 61A Rocks!', 'Bob')
# print(len(b.inbox))  # 2
# print(b.inbox[1].msg)  # 'CS 61A Rocks!'
# print(b.inbox[1].sender.name)  # 'Alice'
