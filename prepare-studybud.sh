#!/bin/bash

# StudyBud Django Deployment Preparation Script
# This script helps prepare the StudyBud project for server deployment

echo "🐍 Preparing StudyBud Django application for deployment..."

cd studyBud/myproject

# Check if requirements.txt exists, if not create it
if [ ! -f "requirements.txt" ]; then
    echo "📝 Creating requirements.txt..."
    cat > requirements.txt << EOF
Django>=5.2.4
django-environ
gunicorn
whitenoise
EOF
    echo "✅ Created requirements.txt with basic Django dependencies"
else
    echo "✅ requirements.txt already exists"
fi

# Check if Procfile exists, if not create it
if [ ! -f "Procfile" ]; then
    echo "📝 Creating Procfile for deployment..."
    cat > Procfile << EOF
web: gunicorn myproject.wsgi:application
EOF
    echo "✅ Created Procfile"
else
    echo "✅ Procfile already exists"
fi

# Check if runtime.txt exists, if not create it
if [ ! -f "runtime.txt" ]; then
    echo "📝 Creating runtime.txt..."
    echo "python-3.12.0" > runtime.txt
    echo "✅ Created runtime.txt"
else
    echo "✅ runtime.txt already exists"
fi

echo ""
echo "🎯 StudyBud deployment files ready!"
echo "📁 Files created in studyBud/myproject/:"
ls -la requirements.txt Procfile runtime.txt 2>/dev/null

echo ""
echo "🚀 Next steps for deployment:"
echo "1. Choose a hosting platform:"
echo "   - Heroku: https://heroku.com"
echo "   - Railway: https://railway.app"  
echo "   - PythonAnywhere: https://pythonanywhere.com"
echo "   - DigitalOcean: https://digitalocean.com"
echo ""
echo "2. Update ALLOWED_HOSTS in settings.py with your domain"
echo "3. Configure environment variables for production"
echo "4. Set up a production database (PostgreSQL recommended)"
echo "5. Configure static files serving"
echo ""
echo "📖 See DEPLOYMENT.md for detailed instructions!"