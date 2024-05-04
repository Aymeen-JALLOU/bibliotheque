<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Library Management System</title>
</head>
<body>
    <h1>Welcome to the Library Management System</h1>
    <p>This program allows users to manage a library of books. Users can search for books, add new books, remove existing books, display all books in the library, and perform sorting operations.</p>
    <h2>User Authentication</h2>
    <p>Please enter your username:</p>
    <form action="">
        <label for="username">Username:</label>
        <input type="text" id="username" name="username">
        <button type="submit">Submit</button>
    </form>
    <h2>Main Menu</h2>
    <p>Choose one of the following options:</p>
    <ul>
        <li>Search for a Book</li>
        <li>Add a new Book</li>
        <li>Remove an existing Book</li>
        <li>Display all Books in the library</li>
        <li>Modify</li>
        <li>Sort</li>
    </ul>
    <h2>Book Management</h2>
    <p>To search for a book, you can search by title or author.</p>
    <p>To add a new book, enter its details:</p>
    <form action="">
        <!-- Form fields for book details -->
        <button type="submit">Add Book</button>
    </form>
    <p>To remove an existing book, enter its ID:</p>
    <form action="">
        <label for="bookId">Book ID:</label>
        <input type="number" id="bookId" name="bookId">
        <button type="submit">Remove Book</button>
    </form>
    <p>To display all books in the library:</p>
    <button>Show Books</button>
    <p>To modify a book, enter its ID and new details:</p>
    <form action="">
        <!-- Form fields for book ID and new details -->
        <button type="submit">Modify Book</button>
    </form>
    <p>To sort books by category or title:</p>
    <form action="">
        <label for="sortOption">Sort by:</label>
        <select id="sortOption" name="sortOption">
            <option value="category">Category</option>
            <option value="title">Title</option>
        </select>
        <button type="submit">Sort</button>
    </form>
</body>
</html>
