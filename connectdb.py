import os
import psycopg2

# Retrieve the connection string from the environment variable
conn_string = os.getenv('DATABASE_URL')

# Print the connection string to verify it's correct
print(f"Connection string: {conn_string}")

try:
    # Connect to the database
    connection = psycopg2.connect(conn_string)

    # Create a cursor object
    cursor = connection.cursor()

    # Execute a query
    cursor.execute("SELECT version();")

    # Fetch and print the result of the query
    result = cursor.fetchone()
    print(result)

    # Close the cursor and connection
    cursor.close()
    connection.close()

except Exception as e:
    print(f"An error occurred: {e}")
