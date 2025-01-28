### Features Checklist

- [x] **Show All Clients**
  - Read accounts from `.txt` as vector of strings.
  - Parse to vector of structs.
  - Print struct details to the console.

- [ ] **Add New Client**
  - Read accounts from `.txt` as vector of strings.
  - Input new client details and parse to a struct.
  - Convert struct to string and append to vector.
  - Overwrite `.txt` file with updated vector.

- [ ] **Delete Client**
  - Extract account number from each line.
  - Match with input for deletion.
  - Confirm and remove matching account.
  - Write updated vector to `.txt`.

- [ ] **Update Client**
  - Find account by number and parse to struct.
  - Modify struct values (except account number).
  - Convert back to string and update vector.
  - Overwrite `.txt` file.

- [ ] **Find Client**
  - Search by account number.
  - Parse matching line to struct.
  - Print struct details.

- [ ] **Transactions**
  - Access account by number and parse to struct.
  - Update balance based on selected operation (deposit/withdraw).
  - Update vector and overwrite `.txt`.

