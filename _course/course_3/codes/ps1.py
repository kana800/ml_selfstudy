"""
Problem Set 1
----

Part A
------

Determine how long it will take you to save enough money to make the
down payment given the following assumptions.
"""

def dreamHouse():
    # down payment of the house
    portion_down_payment = 0.25
    # annual rate
    r = 0.04
    # current savings
#    current_savings = 0 + current_savings * r/12
    # annual salary
    annual_salary = int(input("Enter your annual salary: "))
    # percentage of salary saved for down payment
    portion_saved = float(input("Enter the percent of your salary to save, as a\
                          decimal: "))
    # total cost of my dream house
    total_cost = int(input("Enter the cost of your dream home: "))

    # number of money earned per month
    earned_per_month = annual_salary/12
    # amount of money being saved
    saved_amount = earned_per_month * portion_saved
    # down payment amount
    downpayment = total_cost * 0.25
    # number of months
    number_of_months = int(downpayment / saved_amount)
    print(f"Number of months: {number_of_months}")
