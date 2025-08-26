# Deployment Guide: Single Project Deployment

## What is being deployed?

This repository contains **two separate projects**:

### 1. QuickQuiz - Static Web Application
- **Location**: `/QuickQuiz/`
- **Type**: Frontend-only static website
- **Files**: 
  - `index.html` - Main application page
  - `script.js` - Quiz logic and interactivity  
  - `styles.css` - Custom styling and animations
- **Dependencies**: External CDN libraries (Tailwind CSS, Particles.js, Canvas Confetti)
- **Deployment**: Can be deployed to GitHub Pages, Netlify, Vercel, or any static hosting

### 2. StudyBud - Django Web Application  
- **Location**: `/studyBud/`
- **Type**: Full-stack web application with database
- **Description**: Chat room/study group application with user authentication
- **Deployment**: Requires Python server hosting (Heroku, Railway, DigitalOcean, etc.)

## Current Deployment Setup

### GitHub Pages Configuration
- **Source**: `/docs` folder (contains QuickQuiz files)
- **What's deployed**: Only the QuickQuiz application
- **URL**: Will be available at `https://edenmengste.github.io/simple_projects/`

## How to Deploy Individual Projects

### Option 1: Deploy QuickQuiz Only (Current Setup)
```bash
# Files are automatically copied to /docs folder
# GitHub Pages is configured to serve from /docs
# No additional setup needed
```

### Option 2: Deploy StudyBud Django Application
For the Django application, you'll need a server-capable hosting service:

**Recommended Hosting Options:**
- Heroku (free tier available)
- Railway  
- PythonAnywhere
- DigitalOcean App Platform

**Required Files for Django Deployment:**
```
requirements.txt  # Python dependencies
Procfile         # Process specification
runtime.txt      # Python version
```

### Option 3: Deploy Both Projects Separately
- **QuickQuiz**: Use GitHub Pages (current setup)
- **StudyBud**: Use a Python hosting service

## Manual Deployment Commands

### Deploy QuickQuiz to Different Platforms:

**Netlify:**
```bash
# Drag and drop the /QuickQuiz folder to Netlify dashboard
# Or use Netlify CLI:
cd QuickQuiz
netlify deploy --prod --dir .
```

**Vercel:**
```bash
cd QuickQuiz  
vercel --prod
```

**GitHub Pages (manual):**
```bash
# Copy QuickQuiz files to docs folder (already done)
cp QuickQuiz/* docs/
git add docs/
git commit -m "Update deployed QuickQuiz files"
git push
```

## File Structure Explanation

```
simple_projects/
├── docs/              # 📁 DEPLOYED - QuickQuiz files for GitHub Pages
│   ├── index.html     # ✅ QuickQuiz main page
│   ├── script.js      # ✅ Quiz functionality  
│   └── styles.css     # ✅ Custom styles
├── QuickQuiz/         # 📁 SOURCE - Original QuickQuiz files
│   ├── index.html
│   ├── script.js
│   └── styles.css
├── studyBud/          # 📁 NOT DEPLOYED - Django application
│   └── myproject/     # Requires server hosting
└── README.md
```

## Updating Deployed Content

To update the deployed QuickQuiz:

1. **Edit files in `/QuickQuiz/` folder**
2. **Copy changes to `/docs/` folder**:
   ```bash
   cp QuickQuiz/* docs/
   ```
3. **Commit and push changes**:
   ```bash
   git add docs/
   git commit -m "Update QuickQuiz deployment"
   git push
   ```

## Why This Approach?

### Benefits of Single-Project Deployment:
✅ **Faster deployments** - Only relevant files are processed  
✅ **Cleaner URLs** - No subdirectories in the live site  
✅ **Better performance** - Smaller deployment package  
✅ **Clear separation** - Each project can have its own deployment strategy  
✅ **Easier maintenance** - Update only what's needed

### Previous Issue:
❌ GitHub Pages was looking for a `/docs` directory that didn't exist  
❌ Jekyll was trying to process the entire repository  
❌ Mixed project types caused deployment confusion

### Current Solution:
✅ QuickQuiz files copied to `/docs` for GitHub Pages  
✅ Clean, single-project deployment  
✅ StudyBud remains separate for server deployment