#include <iostream>
#include <string>
#include <time.h>

using namespace std;

struct Song
{
	string name = "DefaultSong";
	string artist;
	string creator;
	string genre;
	string date;
	float duration;
	int id;
};

struct treenode{
	Song song;
	treenode* left;
	treenode* right;
};

void insert(treenode** tree ,Song song){
	if (*tree == NULL){
		*tree = new treenode();
		(*tree)->song = song;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	}
	else{
		if ((*tree)->song.id > song.id)
		{
			insert(&((*tree)->left), song);
		}
		else
		{
			insert(&((*tree)->right), song);
		}
	}
	
}

void printtree(treenode * tree){
	if(tree->left != NULL){
		printtree(tree->left);
	}
	cout << tree->song.id << endl;
	
	if(tree->right != NULL){
		printtree(tree->right);
	}
}

Song findSong(treenode* tree, int id, bool* found)
{	
	if (tree == NULL)
	{
		*found = false;
		return Song();
	}
	
	if (tree->song.id < id)
		return findSong(tree->right, id, found);
	else if (tree->song.id > id)
		return findSong(tree->left, id, found);
	
	*found = true;
	return tree->song;
}

int main()
{
	srand (time(NULL));
	
	Song SongRecords[100];
	bool foundSongs[100];
	
	for(int i = 0; i<100; i++)
	{
		SongRecords[i].name = "Song " + to_string(i);
		SongRecords[i].artist = "Artist " + to_string(i);
		SongRecords[i].creator = "Creator " + to_string(i);
		SongRecords[i].genre = "Genre " + to_string(i);
		SongRecords[i].date = "Date " + to_string(i);
		SongRecords[i].duration = (float)i;
		SongRecords[i].id = i;
		
		foundSongs[i] = false;
	}
	
	int foundSongsCounter = 0;
	treenode* dentro = NULL;
	while (foundSongsCounter < 20){
		
		int n = rand() %100;
		
		if (foundSongs[n] == true)
		{
			continue;
		}
		
		foundSongs[n] = true;
		foundSongsCounter++;
		
		cout << endl;
		cout << "Number " << n << ":";
		cout << endl
		<< "Song: " << SongRecords[n].name 
		<< "\nArtist: " << SongRecords[n].artist 
		<<  "\nCreator: " << SongRecords[n].creator 
		<< "\nGenre: " << SongRecords[n].genre 
		<< "\nDate: " << SongRecords[n].date 
		<< "\nDuration: " << SongRecords[n].duration 
		<< "\nID: " << SongRecords[n].id << endl;
		
		insert(&dentro, SongRecords[n]);
	}
	
	printtree(dentro);
	
	bool s1Found;
	Song s1 = findSong(dentro, 3, &s1Found);
	
	if (s1Found)
		cout << "Found Song: " << s1.name << endl;
	else
		cout << "Song not found!" << endl;
}
		

