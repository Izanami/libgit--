libgitpp
========

libgit++, a wrapper c++ of libgit2

Repositories
------------

### Init(Simple)
```
/* With working directory: */
auto git = Git::Repository::init(“/tmp/…”);
/* …or bare: */
auto git = Git::Repository::init(“/tmp/…”, true);
```

### Clone(Simple)
```
auto git = Git::Repository::clone(“http://…”, “/tmp/…”)
/* With Git::Repository object */
git->clone(“/tmp/…”);
```

### Open (Simple)
```
auto git = Git::Repository::open(“/tmp/…”)
```

### Check If Repository
```
Git::Repository::isRepository(“/tmp/…”);
```
